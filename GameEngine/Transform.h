#pragma once
#include "Component.h"
#include "Vector3.h"

using namespace ESGI;

class Transform : public Component {
private:
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

public:
	Transform();
	Transform(Vector3 pos, Vector3 rot, Vector3 scale);
	
	void setPosition(Vector3 position);
	Vector3 getPosition() const;

	void setRotation(Vector3 rotation);
	Vector3 getRotation() const;

	void setScale(Vector3 scale);
	Vector3 getScale() const;
};