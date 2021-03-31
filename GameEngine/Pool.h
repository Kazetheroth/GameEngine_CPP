#pragma once

#include "Factory.h"

using namespace std;
using namespace ESGI;
using namespace GameObjectArchetype;

class Pool
{
private:
	vector<GameObject*> objects;

public:
	Pool() {};
	Pool(Archetype archetype, int nbInstantiate);

	GameObject* GetPooledObject();
};

class PoolComponent
{
private:
	vector<Component*> components;

public:
	PoolComponent() {};
	PoolComponent(RTTI rtti, int nbInstantiate);

	Component* GetPooledObject();
};