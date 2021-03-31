#include "RTTI.h"
#include "Player.h"
#include "AsciiRenderer.h"

#include "Factory.h"

RTTI RTTI::Default("", *((RTTI*)nullptr));

RTTI::RTTI(const char* name, const RTTI& parent_type = RTTI::Default
) : parent(parent_type) {
	type = name;

	Factory::RegisterRTTI(*this);
}

using namespace GameObjectArchetype;
RTTI_DEFINITION_BASE(Archetype);
RTTI_DEFINITION(Player, Archetype);

RTTI_DEFINITION_BASE(Component);
RTTI_DEFINITION(Transform, Component);
RTTI_DEFINITION(PlayerBehavior, Component);
RTTI_DEFINITION(AsciiRenderer, Component);