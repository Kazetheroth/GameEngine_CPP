#pragma once

#ifndef INCLUDE_GAMEOBJECT
#define INCLUDE_GAMEOBJECT

#include <string>
#include <vector>

#include "Component.h"
#include "JSONBase.h"

using namespace std;

namespace ESGI {
	class GameObject {
	public:
		GameObject();
		~GameObject();

		//virtual bool Deserialize(const rapidjson::Value& obj);
		static GameObject* Deserialize(const rapidjson::Value& obj, bool t);
		//virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;
		static GameObject* FindFirstByTag(string tag);

		string getUid();

		void setTag(string tag);
		string getTag();

		void setName(string name);
		string getName();

		void setIsActivate(bool isActivate);
		bool getIsActivate();

		vector<Component*> getComponents();
		void addComponent(Component* component);
		Component* getComponent(RTTI componentType);

	private:
		string uid;

		string tag;
		string name;
		bool isActivate;
		vector<Component*> components;
	};
}

#endif