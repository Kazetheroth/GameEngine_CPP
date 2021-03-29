#include "PlayerBehavior.h"

PlayerBehavior::PlayerBehavior() {
	this->Init(typeid(PlayerBehavior).name());
}

void PlayerBehavior::Update(vector<Component*> components)
{
	for (Component* compo : components)
	{
		PlayerBehavior* pb = dynamic_cast<PlayerBehavior*>(compo);

		cout << pb->id << endl;
	}
}