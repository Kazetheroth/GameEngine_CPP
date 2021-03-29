#include "Component.h"

namespace ESGI {
	void Component::Init(string name) {
		this->name = name;
	}

	const string Component::getName() const {
		return name;
	}
}