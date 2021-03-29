#pragma once

#include <iostream>
using namespace std;

namespace ESGI {
	class Component {
		public:
			virtual void Init(string name);

			virtual void Start() {}
			virtual void Update() {}
			virtual void Destroy() {}

			const string getName() const;

		private:
			string name;
	};
}