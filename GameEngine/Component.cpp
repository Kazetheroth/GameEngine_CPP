#include "Component.h"

#include "Factory.h"

namespace ESGI {
	bool Component::Deserialize(const rapidjson::Value& obj, GameObject* go)
	{
		gameObject = go;
		return true;
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
		cout << "Component: " << rtti.type << endl;
	}

	RTTI& Component::GetRTTI() {
		return Component::rtti;
	}
}
