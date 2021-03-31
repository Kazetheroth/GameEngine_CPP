
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
		pools[Player::rtti.type] = new Pool(player, 10);

		Archetype arche = Archetype();
		pools[Archetype::rtti.type] = new Pool(arche, 50);
	}
}