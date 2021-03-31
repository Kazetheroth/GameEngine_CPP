#include "Pool.h"

Pool::Pool(Archetype archetype, int nbInstantiate)
{
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


PoolComponent::PoolComponent(RTTI rtti, int nbInstantiate)
{
	components.reserve(nbInstantiate);

	for (int i = 0; i < nbInstantiate; ++i)
	{
		components.push_back(Factory::GetInstance()->CreateComponent(rtti.type));
	}
}

Component* PoolComponent::GetPooledObject()
{
	for (Component* co : components)
	{
		if (co->getGameObject() == nullptr)
		{
			return co;
		}
	}

	return nullptr;
}