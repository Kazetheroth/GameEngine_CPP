#include "PlayerBehavior.h"

PlayerBehavior::PlayerBehavior() {
	string name = typeid(PlayerBehavior).name();
	this->Init(name);
}

void PlayerBehavior::Update(vector<Component*> components)
{
	for (Component* compo : components)
	{
		PlayerBehavior* pb = dynamic_cast<PlayerBehavior*>(compo);

		cout << ">>>> FROM PLAYERBEHAVIOR " << pb->id << endl;
	}
}