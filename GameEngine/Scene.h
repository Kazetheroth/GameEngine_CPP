#pragma once
#include <string>
#include "GameObject.h"
#include "JSONBase.h"
#include "Vector3.h"

using namespace std;

namespace ESGI
{
	class Scene : public JSONBase
	{
		public:
			Scene();
			virtual ~Scene();
			//virtual bool Deserialize(const string& s);
			virtual bool Deserialize(const rapidjson::Value& obj);
			virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;

			// GETTER - SETTER
			const string& Name() const { return name; }
			void Name(const string& name) { this->name = name; }

			const Vector3& Size() const { return size; }
			void Size(const Vector3& size) { this->size = size; }
		private:
			Vector3 size; // 4,4
			string name;
			//vector<GameObject*> gameObjects;
	};
}
