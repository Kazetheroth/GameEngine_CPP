#include "Component.h"

namespace ESGI {
	Component::Component() {
		this->Init("Component");
	}

	void Component::Init(string name) {
		this->name = name;
	}

	const string Component::getName() const {
		return name;
	}
}