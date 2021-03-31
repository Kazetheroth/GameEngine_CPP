
#include "Scene.h"

namespace ESGI
{
	vector<vector<char>> Scene::sceneAscii = {};
	Vector3 Scene::size = Vector3(0, 0, 0);

	Scene::Scene() : name("null")
	{ }
	Scene::~Scene()
	{ }
	
	bool Scene::Deserialize(const rapidjson::Value& obj)
	{
		Size(Vector3(obj["size"]["x"].GetFloat(), obj["size"]["y"].GetFloat(), obj["size"]["z"].GetFloat()));
		Name(obj["name"].GetString());

		vector<char> chars;
		for (int i = 0; i < size.x; ++i) {
			chars.clear();

			for (int j = 0; j < size.y; ++j) {
				chars.push_back('#');
			}

			sceneAscii.push_back(chars);
		}

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

	void Scene::DisplayScene() {
		system("CLS");

		string displayedScene = "";
		for (vector<char> charCol : sceneAscii) {
			for (char c : charCol) {
				displayedScene += c;
			}

			displayedScene += "\n";
		}

		cout << displayedScene << endl;
	}

	void Scene::ClearScene() {
		for (int i = 0; i < size.x; ++i) {
			for (int j = 0; j < size.y; ++j) {
				sceneAscii[i][j] = '#';
			}
		}
	}
}
