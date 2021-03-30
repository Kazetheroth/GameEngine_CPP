#pragma once

#include "Archetype.h"
#include "PlayerBehavior.h"
#include "Transform.h"

namespace GameObjectArchetype
{
	class Player : public Archetype
	{
		public:
			Player()
			{
				archetypeTag = "Player";
				components.reserve(2);
				components.push_back(typeid(Transform).name());
				components.push_back(typeid(PlayerBehavior).name());
			}
	};
}
