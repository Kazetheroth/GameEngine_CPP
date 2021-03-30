#pragma once
#include <string>
#include <vector>

using namespace std;

namespace GameObjectArchetype
{
	struct Archetype
	{
		string archetypeTag;
		vector<string> components;
	};
}