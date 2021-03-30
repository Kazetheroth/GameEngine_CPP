#include "Transform.h";

Transform::Transform()
{
	this->Init(typeid(Transform).name());

	position = Vector3(0, 0, 0);
	rotation = Vector3(0, 0, 0);
	scale = Vector3(0, 0, 0);
}

Transform::Transform(Vector3 pos, Vector3 rot, Vector3 scale)
{
	this->Init(typeid(Transform).name());

	position = pos;
	rotation = rot;
	this->scale = scale;
}

bool Transform::Deserialize(const rapidjson::Value& obj)
{
	setPosition(Vector3(obj["position"]["x"].GetFloat(), obj["position"]["y"].GetFloat(), obj["position"]["z"].GetFloat()));
	setRotation(Vector3(obj["rotation"]["x"].GetFloat(), obj["rotation"]["y"].GetFloat(), obj["rotation"]["z"].GetFloat()));
	setScale(Vector3(obj["scale"]["x"].GetFloat(), obj["scale"]["y"].GetFloat(), obj["scale"]["z"].GetFloat()));
	return true;
}

bool Transform::Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const
{
	return false;
}

void Transform::setPosition(Vector3 position) {
	this->position = position;
}
Vector3 Transform::getPosition() const {
	return position;
}

void Transform::setRotation(Vector3 rotation) {
	this->rotation = rotation;
}
Vector3 Transform::getRotation() const {
	return rotation;
}

void Transform::setScale(Vector3 scale) {
	this->scale = scale;
}
Vector3 Transform::getScale() const {
	return scale;
}