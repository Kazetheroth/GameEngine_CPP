#include "Component.h"

#include "Factory.h"

namespace ESGI {
	Component::Component() {
		this->Init(typeid(Component).name());
	}

	bool Component::Deserialize(const rapidjson::Value& obj, GameObject* go)
	{
		gameObject = go;
		return true;
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

	GameObject* Component::getGameObject()
	{
		return gameObject;
	}

	void Component::printComponent()
	{
		cout << "Component: " << this->name << endl;
	}
}
