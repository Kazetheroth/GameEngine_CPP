#pragma once

#ifndef INCLUDE_ARCHETYPE
#define INCLUDE_ARCHETYPE

#include <vector>
#include <string>

#include "RTTI.h"

using namespace std;

namespace GameObjectArchetype
{
	struct Archetype
	{
		RTTI_DECLARATION;

		string archetypeTag;
		vector<string> components;
	};
}

#endif
