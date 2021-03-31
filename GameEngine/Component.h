#pragma once

#ifndef INCLUDE_COMPONENT
#define INCLUDE_COMPONENT

#include <iostream>
#include <vector>
#include "JSONBase.h"
#include "RTTI.h"

using namespace std;

namespace ESGI {

	class GameObject;
	
	class Component {
		public:

			RTTI_DECLARATION;
		
			Component() {};
			~Component() {}

			virtual bool Deserialize(const rapidjson::Value& obj, GameObject* go);
			
			virtual void Init() {};

			virtual void Start() {}
			virtual void Update(vector<Component*> components) {}
			virtual void Destroy() {}

			virtual RTTI& GetRTTI();

			void setGameObject(GameObject* gameObject);
			GameObject* getGameObject();
			virtual void printComponent();

		private:
			GameObject* gameObject;
	};
}

#endif