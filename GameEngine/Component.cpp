#include "Component.h"

namespace ESGI {
	Component::Component() {
		this->Init(typeid(Component).name());
	}

	bool Component::Deserialize(const rapidjson::Value& obj)
	{
		Init(obj["name"].GetString());
		return true;
	}

	bool Component::Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const
	{
		return false;
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