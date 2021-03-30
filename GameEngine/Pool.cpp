#include "Pool.h"

Pool::Pool(Archetype archetype, int nbInstantiate)
{
	this->archetype = archetype;
	this->nbObjectInstantiate = nbInstantiate;

	objects.reserve(nbInstantiate);
	
	for (int i = 0; i < nbInstantiate; ++i)
	{
		objects.push_back(Factory::GetInstance()->InstantiateArchetype(archetype));
		objects[i]->setIsActivate(false);
	}
}

GameObject* Pool::GetPooledObject()
{
	for (GameObject* go : objects)
	{
		if (!go->getIsActivate())
		{
			return go;
		}
	}

	return nullptr;
}