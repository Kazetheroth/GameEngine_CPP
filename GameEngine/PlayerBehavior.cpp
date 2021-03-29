#include "PlayerBehavior.h"

PlayerBehavior::PlayerBehavior() {
	string name = typeid(PlayerBehavior).name();
	this->Init(name);
}

void PlayerBehavior::Update(vector<shared_ptr<Component>> components)
{
	for (shared_ptr<Component> compo : components)
	{
		shared_ptr<PlayerBehavior> pb = dynamic_pointer_cast<PlayerBehavior>(compo);

		cout << ">>>> FROM PLAYERBEHAVIOR " << pb->id << endl;
	}
}