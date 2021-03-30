#pragma once
#include <map>
#include <functional>

#include "Archetype.h"
#include "Component.h"
#include "GameObject.h"

using namespace GameObjectArchetype;

namespace ESGI
{
	class Factory
	{
		protected:
			Factory();
			static Factory* factoryInstance;

		private:
			Component* InstantiateComponent(string type);

		public:
			static Factory* GetInstance();
		
			typedef map<string, vector<Component*>> ComponentMap;
			ComponentMap components;

			typedef map<string, vector<GameObject*>> GameObjectMap;
			GameObjectMap objects;

			map<string, function<Component* (void)>> factoryComponentRegistry;

			void RegisterComponentFunction(string name, function<Component* (void)> classFunction);
			Component* CreateComponent(string componentType);

			GameObject* InstantiateArchetype(Archetype archetype);

			void DestroyObjects();
	};
}