#include "PlayerBehavior.h"

#include "GameObject.h"

PlayerBehavior::PlayerBehavior() {
}

bool PlayerBehavior::Deserialize(const rapidjson::Value& obj, GameObject* go)
{
	Component::Deserialize(obj, go);
	id = obj["id"].GetInt();
	return true;
}

bool PlayerBehavior::Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const
{
	return false;
}

void PlayerBehavior::Update(vector<Component*> components)
{
	for (Component* compo : components)
	{	
		PlayerBehavior* pb = dynamic_cast<PlayerBehavior*>(compo);

		cout << ">>>> FROM PLAYERBEHAVIOR " << pb->id << endl;
	}
}

void PlayerBehavior::printComponent()
{
	cout << "Player Id: " << this->id << endl;
}
