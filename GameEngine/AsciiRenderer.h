#pragma once
#include "Component.h"

using namespace ESGI;

class AsciiRenderer : public Component
{
public:
	RTTI_DECLARATION;

	char ascii;

	AsciiRenderer();
	virtual bool Deserialize(const rapidjson::Value& obj, GameObject* go);
	virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;

	virtual void Update(vector<Component*> components);
	virtual void printComponent();

	virtual RTTI& GetRTTI();
};