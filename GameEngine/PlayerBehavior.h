#pragma once

#include "Component.h"

using namespace ESGI;

class PlayerBehavior : public Component
{
private:
public:
	int id = 1000;
	PlayerBehavior();
	
	virtual void Update(vector<Component*> components);
};
