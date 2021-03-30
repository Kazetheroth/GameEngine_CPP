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

		return true;
	}
	
	bool Scene::Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const
	{
		return true;
	}

}
