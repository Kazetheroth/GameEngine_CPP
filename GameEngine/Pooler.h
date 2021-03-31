#pragma once

#include "Pool.h"
#include "Player.h"
#include "AsciiRenderer.h"

namespace ESGI
{
	class Pooler
	{
	private:
		Pooler();
		static Pooler* instance;

	public:
		static Pooler* GetInstance();
		static void InstantiatePooler();

		map<string, Pool*> poolObjects;
		map<string, PoolComponent*> poolComponents;
	};
}
