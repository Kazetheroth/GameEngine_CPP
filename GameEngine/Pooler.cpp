
#include "Pooler.h"

namespace ESGI
{
	Pooler* Pooler::instance = nullptr;

	void Pooler::InstantiatePooler() {
		if (instance == nullptr) {
			instance = new Pooler();
		}
	}

	Pooler* Pooler::GetInstance() {
		if (instance == nullptr) {
			instance = new Pooler();
		}

		return instance;
	}

	Pooler::Pooler()
	{
		Player player = Player();
		pools[player.archetypeTag] = new Pool(player, 20);
	}
}