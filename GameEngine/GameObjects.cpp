#include "GameObjects.h"

bool ESGI::GameObjects::Deserialize(const std::string& s)
{
	cout << "Debug Deserialize GameObjects" << endl;
	rapidjson::Document doc;
	if (!InitDocument(s, doc))
		return false;

	if (!doc.IsArray())
		return false;

	for (rapidjson::Value::ConstValueIterator itr = doc.Begin(); itr != doc.End(); ++itr)
	{
		GameObject go;
		go.Deserialize(*itr);
		gameObjects.push_back(go);
	}

	return true;
}

bool ESGI::GameObjects::Deserialize(const rapidjson::Value& obj)
{
	cout << "Hello on est dans le bon deserialize" << endl;
	for (rapidjson::Value::ConstValueIterator itr = obj.Begin(); itr != obj.End(); ++itr)
	{
		GameObject go;
		go.Deserialize(*itr);
		gameObjects.push_back(go);
	}
	return true;
};

bool ESGI::GameObjects::Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const
{
	return false;
}


