#pragma once
#include <vector>

#include "Component.h"

using namespace ESGI;

class SceneManager: public Component {
private:
	vector<GameObject*> pooledObject;

public:
	RTTI_DECLARATION;

	char ascii;

	SceneManager();
	virtual bool Deserialize(const rapidjson::Value& obj, GameObject* go);
	virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;

	virtual void Update(vector<Component*> components);
	virtual void printComponent();

	virtual RTTI& GetRTTI();
};