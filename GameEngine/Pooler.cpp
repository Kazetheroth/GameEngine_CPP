
#include "Pooler.h"

namespace ESGI
{
	Pooler::PoolMap Pooler::pools = { };

	Pooler::Pooler()
	{
		Player player = Player();
		pools[player.archetypeTag] = new Pool(player, 20);
	}
}