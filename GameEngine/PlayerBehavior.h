#pragma once

#include "Component.h"

using namespace ESGI;

class PlayerBehavior : public Component
{
private:
public:
	RTTI_DECLARATION;

	int id;
	PlayerBehavior();
	virtual bool Deserialize(const rapidjson::Value& obj, GameObject* go);
	virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;
	
	virtual void Update(vector<Component*> components);
	virtual void printComponent();

	virtual RTTI& GetRTTI();
};
