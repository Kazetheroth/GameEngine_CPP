#include "Engine.h"

// par contre lors de la definition de la fonction il faut une implementation complete
#include "EngineContext.h"
#include "Timer.h"
#include "Input.h"

#include <Windows.h>

#include "Pooler.h"

namespace ESGI {

	void Engine::ProcessSystems(double elapsedTime)
	{
		EngineSystem& system = *m_AIEngine;

		system.accumulatedTime += elapsedTime;

		float deltaTime = static_cast<float>(elapsedTime);

		system.Update(deltaTime);

		int loops = system.maxIterations;
		// on sort de la boucle des que l'un des deux tests est faux
		while ((system.accumulatedTime > system.targetFrameRate) && (loops > 0))
		{
			system.accumulatedTime -= system.targetFrameRate;

			// alternativement on pourrait recalculer le deltaTime a chaque tour de boucle
			// et rappeler Update() si loops < system.maxIterations

			system.FixedUpdate(static_cast<float>(system.targetFrameRate));

			--loops;			
		}
	}

	bool Engine::Initialize()
	{
#if defined(_DEBUG)
		m_DebugName = "Engine";
#endif

		// Les systemes pourraient etre cree de facon data-driven, plugins, ou en dur
		EngineSystem* system = new EngineSystem;
		system->Create();
		system->Initialize();

		m_AIEngine = system;

		std::cout << "[Engine] initialized\n";

		return true;
	}

	void Engine::DeInitialize()
	{
		// libere et detruit les systems
		m_AIEngine->DeInitialize();
		m_AIEngine->Destroy();

		std::cout << "[Engine] deinitialized\n";
	}

	void UpdateLambda(vector<Component*> componentIn)
	{
		componentIn[0]->Update(componentIn);
	}

	vector<Component*> GetActiveObject(vector<Component*> components)
	{
		vector<Component*> activeComponent;

		for (Component* component : components)
		{
			if (component->getGameObject() != nullptr && component->getGameObject()->getIsActivate())
			{
				activeComponent.push_back(component);
			}	
		}

		return activeComponent;
	}
	
	void Engine::RunUpdate(EngineContext& context) {
		double elapsedTime = context.clock.ElapsedTime;

		componentsThread.clear();
		componentsThread.reserve(Factory::GetInstance()->components.size());
	
		for (pair<string, vector<Component*>> components : Factory::GetInstance()->components)
		{
			vector<Component*> componentIn = GetActiveObject(components.second);
			
			if (componentIn.empty())
			{
				continue;
			}

			function<void(vector<Component*>)> function = UpdateLambda;
			componentsThread.push_back(thread(function, componentIn));
		}

		for (int i = 0; i < componentsThread.size(); ++i)
		{
			componentsThread[i].join();
		}

		Input::inputsPressed.clear();

		// tout lag est maximise 100 ms (1/10 de seconde)
		// cela permet d'eviter de faire sauter le moteur en cas de breakpoint ou lag enorme
		// alternativement on peut appliquer une correction en extrapolant a partir du temps ecoule 
		if (elapsedTime > 0.10)
			elapsedTime = 0.10;

		ProcessSystems(elapsedTime);
	}

	// ce n'est pas une fonction virtuelle !
	thread Engine::Update(EngineContext& context)
	{
		return thread(&Engine::RunUpdate, this, context);
	}

}
