#include "GameObject.h"
#include "Utils.h"

namespace ESGI {
	GameObject::GameObject() {
		uid = Utils::GenRandomString(36);
	}

	string GameObject::getUid() {
		return uid;
	}

	void GameObject::setTag(string tag) {
		this->tag = tag;
	}
	string GameObject::getTag() {
		return tag;
	}

	void GameObject::setName(string name) {
		this->name = name;
	}
	string GameObject::getName() {
		return name;
	}

	void GameObject::setIsActivate(bool isActivate) {
		this->isActivate = isActivate;
	}
	bool GameObject::getIsActivate() {
		return isActivate;
	}

	vector<Component*> GameObject::getComponents() {
		return components;
	}
	void GameObject::addComponent(Component* newComponent) {
		bool findSameComponent = false;
		
		for (Component* component : components) {
			if (component->getName()._Equal(newComponent->getName())) {
				findSameComponent = true;
				break;
			}
		}

		if (!findSameComponent) {
			components.push_back(newComponent);
		}
	}

	Component* GameObject::getComponent(string componentName) {
		Component* componentSearched = nullptr;

		for (Component* component : components) {
			if (component->getName()._Equal(componentName)) {
				componentSearched = component;
				break;
			}
		}

		return componentSearched;
	}

	string serialize() {
		return "";
	}
}