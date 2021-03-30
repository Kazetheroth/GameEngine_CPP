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

	vector<shared_ptr<Component>> GameObject::getComponents() {
		return components;
	}
	void GameObject::addComponent(shared_ptr<Component> newComponent) {
		bool findSameComponent = false;
		
		for (shared_ptr<Component> component : components) {
			if (component->getName()._Equal(newComponent->getName())) {
				findSameComponent = true;
				break;
			}
		}

		if (!findSameComponent) {
			components.push_back(newComponent);
		}
	}

	shared_ptr<Component> GameObject::getComponent(string componentName) {
		shared_ptr<Component> componentSearched = nullptr;

		for (shared_ptr<Component> component : components) {
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