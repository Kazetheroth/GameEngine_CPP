#include "SceneManager.h"

#include "Input.h"
#include "Pooler.h"

SceneManager::SceneManager() {
}

bool SceneManager::Deserialize(const rapidjson::Value& obj, GameObject* go)
{
	Component::Deserialize(obj, go);
	return true;
}

bool SceneManager::Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const
{
	return false;
}

void SceneManager::Update(vector<Component*> components)
{
	for (Component* compo : components)
	{
		SceneManager* sceneManager = dynamic_cast<SceneManager*>(compo);

		for (int input : Input::inputsPressed) {
			GameObject* go;

			AsciiRenderer* renderer;
			Transform* transform;

			Vector3 pos;

			switch (input) {
				// I
			case 105:
				go = Pooler::GetInstance()->poolObjects[Player::rtti.type]->GetPooledObject();

				renderer = dynamic_cast<AsciiRenderer*>(go->getComponent(AsciiRenderer::rtti));
				transform = dynamic_cast<Transform*>(go->getComponent(Transform::rtti));
				pos = Vector3(1, 1, 0);

				transform->setPosition(pos);

				renderer->ascii = 'H';

				go->setIsActivate(true);

				sceneManager->pooledObject.push_back(go);

				break;
				// R
			case 114:
				if (sceneManager->pooledObject.size() > 0) {
					sceneManager->pooledObject[0]->setIsActivate(false);
					sceneManager->pooledObject.erase(sceneManager->pooledObject.begin(), sceneManager->pooledObject.begin() + 1);
				}

				break;
			}
		}
	}
}

void SceneManager::printComponent()
{
	cout << "Ascii : " << this->ascii << endl;
}

RTTI& SceneManager::GetRTTI() {
	return SceneManager::rtti;
}