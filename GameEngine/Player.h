#pragma once

#include "Archetype.h"
#include "PlayerBehavior.h"
#include "Transform.h"
#include "AsciiRenderer.h"

namespace GameObjectArchetype
{
	class Player : public Archetype
	{
		public:
			RTTI_DECLARATION;

			Player()
			{
				components.reserve(2);
				components.push_back(Transform::rtti.type);
				components.push_back(PlayerBehavior::rtti.type);
				components.push_back(AsciiRenderer::rtti.type);
			}
	};
}
