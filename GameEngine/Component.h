#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace ESGI {
	class Component {
		public:
			Component();

			virtual void Init(string name);

			virtual void Start() {}
			virtual void Update(vector<Component*> components) {}
			virtual void Destroy() {}

			const string getName() const;

		private:
			string name;
	};
}