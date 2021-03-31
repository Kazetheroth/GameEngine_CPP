#include "AsciiRenderer.h"
#include "Transform.h"

#include "GameObject.h"
#include "Scene.h"

AsciiRenderer::AsciiRenderer() {
}

bool AsciiRenderer::Deserialize(const rapidjson::Value& obj, GameObject* go)
{
	Component::Deserialize(obj, go);
	ascii = obj["ascii"].GetString()[0];
	return true;
}

bool AsciiRenderer::Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const
{
	return false;
}

void AsciiRenderer::Update(vector<Component*> components)
{
	for (Component* compo : components)
	{
		AsciiRenderer* pb = dynamic_cast<AsciiRenderer*>(compo);
		Transform* transform = dynamic_cast<Transform*>(compo->getGameObject()->getComponent(Transform::rtti));

		GameObject* g = compo->getGameObject();
		Vector3 pos = transform->getPosition();

		Scene::sceneAscii[pos.x][pos.y] = ascii;
	}
}

void AsciiRenderer::printComponent()
{
	cout << "Ascii : " << this->ascii << endl;
}

RTTI& AsciiRenderer::GetRTTI() {
	return AsciiRenderer::rtti;
}