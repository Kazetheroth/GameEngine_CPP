#pragma once

#include <string>
#include <vector>

#include "Component.h"
#include "JSONBase.h"

using namespace std;

namespace ESGI {
	class GameObject : public JSONBase {
	public:
		GameObject();
		~GameObject();

		virtual bool Deserialize(const rapidjson::Value& obj);
		virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;

		string getUid();

		void setTag(string tag);
		string getTag();

		void setName(string name);
		string getName();

		void setIsActivate(bool isActivate);
		bool getIsActivate();

		vector<Component*> getComponents();
		void addComponent(Component* component);
		Component* getComponent(string componentName);

		string serialize();

	private:
		string uid;

		string tag;
		string name;
		bool isActivate;
		vector<Component*> components;
	};
}