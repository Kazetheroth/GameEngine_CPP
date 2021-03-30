#include "Factory.h"

namespace ESGI
{
	Factory* Factory::factoryInstance = nullptr;

	Factory::Factory() {}
	
	Factory* Factory::GetInstance()
	{
		if (factoryInstance == nullptr)
		{
			factoryInstance = new Factory();
			factoryInstance->components = {};
			factoryInstance->objects = {};
		}

		return factoryInstance;
	}

	void Factory::RegisterComponentFunction(string name, function<Component*(void)> classFunction)
	{
		factoryComponentRegistry[name] = classFunction;
	}

	shared_ptr<Component> Factory::InstantiateComponent(string type)
	{
		Component* compo = nullptr;

		auto it = factoryComponentRegistry.find(type);
		if (it != factoryComponentRegistry.end())
		{
			compo = it->second();
		}
		else
		{
			return nullptr;
		}
		
		return shared_ptr<Component>(compo);
	}
	
	shared_ptr<Component> Factory::CreateComponent(string componentType)
	{
		shared_ptr<Component> compo = InstantiateComponent(componentType);

		if (compo == nullptr)
		{
			return nullptr;
		}

		if (components.count(componentType) == 0)
		{
			vector<shared_ptr<Component>> componentsList;
			componentsList.push_back(compo);

			components.insert(pair<string, vector<shared_ptr<Component>>>(componentType, componentsList));
		}
		else
		{
			vector<shared_ptr<Component>> componentsList = components.at(componentType);
			componentsList.push_back(compo);
			components[componentType] = componentsList;
		}

		return compo;
	}

	GameObject* Factory::InstantiateArchetype(Archetype archetype)
	{
		GameObject* gameObject = new GameObject();
		gameObject->setName("name");
		gameObject->setTag(archetype.archetypeTag);
		gameObject->setIsActivate(false);

		for (string compoType : archetype.components)
		{
			shared_ptr<Component> newComponent = CreateComponent(compoType);
			newComponent->setGameObject(gameObject);

			gameObject->addComponent(newComponent);
		}

		if (objects.count(archetype.archetypeTag) == 0)
		{
			vector<GameObject*> gameObjects;
			gameObjects.push_back(gameObject);

			objects.insert(pair<string, vector<GameObject*>>(archetype.archetypeTag, gameObjects));
		}
		else
		{
			vector<GameObject*> gameObjects = objects.at(archetype.archetypeTag);
			gameObjects.push_back(gameObject);
			objects[archetype.archetypeTag] = gameObjects;
		}

		return gameObject;
	}
}
