#pragma once
#include <map>
#include <functional>

#include "Component.h"
#include "GameObject.h"

namespace ESGI
{
	class Factory
	{
		protected:
			Factory();
			static Factory* factoryInstance;

		private:
			shared_ptr<Component> InstantiateComponent(string type);

		public:
			static Factory* GetInstance();
		
			typedef map<string, vector<shared_ptr<Component>>> ComponentMap;
			ComponentMap components;

			typedef map<string, vector<GameObject>> GameObjectMap;
			GameObjectMap objects;

			map<string, function<Component* (void)>> factoryComponentRegistry;

			void RegisterComponentFunction(string name, function<Component* (void)> classFunction);
			shared_ptr<Component> CreateComponent(string componentType);
	};
}