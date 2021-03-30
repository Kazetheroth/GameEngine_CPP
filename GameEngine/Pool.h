#pragma once

#include "Factory.h"

using namespace std;
using namespace ESGI;
using namespace GameObjectArchetype;

class Pool
{
private:
	vector<GameObject*> objects;
	Archetype archetype;
	int nbObjectInstantiate;

public:
	Pool() {};
	Pool(Archetype archetype, int nbInstantiate);

	GameObject* GetPooledObject();
};