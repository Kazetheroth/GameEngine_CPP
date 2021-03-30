#include "Scene.h"


namespace ESGI
{
	Scene::Scene() : size(0, 0, 0), name("null")
	{ }
	Scene::~Scene()
	{ }
	
	bool Scene::Deserialize(const rapidjson::Value& obj)
	{
		
		Size(Vector3(obj["size"]["x"].GetFloat(), obj["size"]["y"].GetFloat(), obj["size"]["z"].GetFloat()));
		Name(obj["name"].GetString());
		cout << "Hello on est dans le bon deserialize" << endl;
		for (rapidjson::Value::ConstValueIterator itr = obj["gameObjects"].Begin(); itr != obj["gameObjects"].End(); ++itr)
		{
			GameObject* go = GameObject::Deserialize(*itr, true);
			gameObjects.push_back(go);
		}
		
		return true;
	}
	
	bool Scene::Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const
	{
		return true;
	}

}
