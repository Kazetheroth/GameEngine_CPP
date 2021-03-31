#include "GameObject.h"

#include "Factory.h"
#include "Utils.h"
#include "Pooler.h"

namespace ESGI {
	GameObject::GameObject() {
		uid = Utils::GenRandomString(36);
	}

	GameObject::~GameObject()
	{
		for (Component* component : components)
		{
			delete component;
		}
	}

	GameObject* GameObject::Deserialize(const rapidjson::Value& obj, bool t)
	{
		cout << "Debug Deserialize GameObject" << endl;

		GameObject* go = Pooler::GetInstance()->poolObjects[Archetype::rtti.type]->GetPooledObject();

		go->setName(obj["name"].GetString());
		go->setTag(obj["tag"].GetString());
		go->setIsActivate(obj["isActive"].GetBool());
		for (rapidjson::Value::ConstValueIterator itr = obj["components"].Begin(); itr != obj["components"].End(); ++itr)
		{
			Component* co = Pooler::GetInstance()->poolComponents[(*itr)["name"].GetString()]->GetPooledObject();
			co->Deserialize((*itr), go);
			go->addComponent(co);
		}

		return go;
	}

	GameObject* GameObject::FindFirstByTag(string tag)
	{
		cout << "Debug FindPlayer" << endl;
		for (GameObject* go : Pooler::GetInstance()->poolObjects[Archetype::rtti.type]->GetObjects())
		{
			if (go->getTag() == tag)
			{
				return go;
			}
		}
		return nullptr;
	}

	string GameObject::getUid() {
		return uid;
	}

	void GameObject::setTag(string tag) {
		this->tag = tag;
	}
	string GameObject::getTag() {
		return tag;
	}

	void GameObject::setName(string name) {
		this->name = name;
	}
	string GameObject::getName() {
		return name;
	}

	void GameObject::setIsActivate(bool isActivate) {
		this->isActivate = isActivate;
	}
	bool GameObject::getIsActivate() {
		return isActivate;
	}

	vector<Component*> GameObject::getComponents() {
		return components;
	}
	void GameObject::addComponent(Component* newComponent) {
		bool findSameComponent = false;
		
		for (Component* component : components) {
			if (component->rtti.IsA(newComponent->rtti)) {
				findSameComponent = true;
				break;
			}
		}

		if (!findSameComponent) {
			components.push_back(newComponent);
		}
	}

	Component* GameObject::getComponent(RTTI componentType) {
		Component* componentSearched = nullptr;

		for (Component* component : components) {
			if (component->rtti.IsA(componentType)) {
				componentSearched = component;
				break;
			}
		}

		return componentSearched;
	}
}