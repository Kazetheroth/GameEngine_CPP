#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace ESGI {

	class GameObject;
	
	class Component {
		public:
			Component();
			~Component() {}

			virtual void Init(string name);

			virtual void Start() {}
			virtual void Update(vector<Component*> components) {}
			virtual void Destroy() {}

			const string getName() const;

			void setGameObject(GameObject* gameObject);
			const GameObject* getGameObject() const;

		private:
			string name;
			GameObject* gameObject;
	};
}