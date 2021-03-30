#pragma once

#include "Pool.h"
#include "Player.h"

namespace ESGI
{
	class Pooler
	{
	public:
		Pooler();

		typedef map<string, Pool*> PoolMap;
		static PoolMap pools;
	};
}
