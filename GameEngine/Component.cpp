#include "Component.h"

namespace ESGI {
	Component::Component() {
		this->Init(typeid(Component).name());
	}

	void Component::Init(string name) {
		this->name = name;
	}

	const string Component::getName() const {
		return name;
	}

	void Component::setGameObject(GameObject* gameObject)
	{
		this->gameObject = gameObject;
	}

	const GameObject* Component::getGameObject() const
	{
		return gameObject;
	}
}