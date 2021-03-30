#pragma once

#include "Component.h"

using namespace ESGI;

class PlayerBehavior : public Component
{
private:
public:
	int id;
	PlayerBehavior();
	virtual bool Deserialize(const rapidjson::Value& obj);
	virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;
	
	virtual void Update(vector<Component*> components);
};
