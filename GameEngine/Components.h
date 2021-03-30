#pragma once
#include <list>
#include "Component.h"
#include "JSONBase.h"

namespace ESGI
{
	class Components : public JSONBase
	{
	public:
		virtual ~Components() {};
		virtual bool Deserialize(const std::string& s);

		// Getters/Setters.
		std::list<Component>& GameObjectsList() { return components; }
		virtual bool Deserialize(const rapidjson::Value& obj) { return false; };
		virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;
	private:
		std::list<Component> components;
	};
}

