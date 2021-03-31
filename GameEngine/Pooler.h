#pragma once

#include "Pool.h"
#include "Player.h"

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

		typedef map<string, Pool*> PoolMap;
		PoolMap pools;
	};
}
