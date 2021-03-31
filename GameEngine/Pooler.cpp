
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
		poolObjects[Player::rtti.type] = new Pool(player, 10);

		Archetype arche = Archetype();
		poolObjects[Archetype::rtti.type] = new Pool(arche, 50);

		poolComponents[Transform::rtti.type] = new PoolComponent(Transform::rtti, 20);
		poolComponents[PlayerBehavior::rtti.type] = new PoolComponent(PlayerBehavior::rtti, 20);
		poolComponents[AsciiRenderer::rtti.type] = new PoolComponent(AsciiRenderer::rtti, 20);
	}
}