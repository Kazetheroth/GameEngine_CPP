#pragma once
#include <list>
#include "GameObject.h"
#include "JSONBase.h"

namespace ESGI
{
	class GameObjects : public JSONBase
	{
	public:
		virtual ~GameObjects() {};
		virtual bool Deserialize(const std::string& s);

		// Getters/Setters.
		std::list<GameObject>& GameObjectsList() { return gameObjects; }
		virtual bool Deserialize(const rapidjson::Value& obj);
		virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;
	private:
		std::list<GameObject> gameObjects;
	};
}

