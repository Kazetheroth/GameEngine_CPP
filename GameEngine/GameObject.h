#pragma once

#include <string>
#include <vector>

#include "Component.h"

using namespace std;

namespace ESGI {
	class GameObject {
	public:
		GameObject();

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