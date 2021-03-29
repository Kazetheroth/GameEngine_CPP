#include "Component.h"

namespace ESGI {
	Component::Component() {
		this->Init(typeid(Component).name());
	}

	void Component::Init(string name) {
		this->name = name;
	}

	const string Component::getName() const {
		return name;
	}
}