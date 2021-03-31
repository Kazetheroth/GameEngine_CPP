#include "PlayerBehavior.h"

#include "GameObject.h"
#include "Input.h"
#include "Transform.h"
#include "Scene.h"

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

		if (Input::inputsPressed.size() > 0) {
			Transform* transform = dynamic_cast<Transform*>(compo->getGameObject()->getComponent(Transform::rtti));
			Vector3 pos = transform->getPosition();

			for (int input : Input::inputsPressed) {
				switch (input) {
					// Z
				case 122:
					if (pos.x > 0) {
						pos.x -= 1;
					}
					break;
					// Q
				case 113:
					if (pos.y > 0) {
						pos.y -= 1;
					}
					break;
					// S
				case 115:
					if (pos.x < Scene::size.x - 1) {
						pos.x += 1;
					}
					break;
					// D
				case 100:
					if (pos.y < Scene::size.y - 1) {
						pos.y += 1;
					}
					break;
				}
			}

			transform->setPosition(pos);
		}
	}
}

void PlayerBehavior::printComponent()
{
	cout << "Player Id: " << this->id << endl;
}


RTTI& PlayerBehavior::GetRTTI() {
	return PlayerBehavior::rtti;
}