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
	
	shared_ptr<Component> Factory::CreateComponent(string componentType)
	{
		Component* compo = nullptr;
		
		auto it = factoryComponentRegistry.find(componentType);
		if (it != factoryComponentRegistry.end())
		{
			compo = it->second();
		} else
		{
			return nullptr;
		}

		if (components.count(componentType) == 0)
		{
			vector<Component*> componentsList;
			componentsList.push_back(compo);

			components.insert(pair<string, vector<Component*>>(componentType, componentsList));
		}
		else
		{
			vector<Component*> componentsList = components.at(componentType);
			componentsList.push_back(compo);
		}

		return shared_ptr<Component>(compo);
	}
}
