#include "RTTI.h"
#include "Player.h"

RTTI RTTI::Default("", *((RTTI*)nullptr));

RTTI::RTTI(const char* name, const RTTI& parent_type = RTTI::Default
) : parent(parent_type) {
	type = name;
}

using namespace GameObjectArchetype;
RTTI_DEFINITION_BASE(Archetype);
RTTI_DEFINITION(Player, Archetype);