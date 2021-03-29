#pragma once

#include "InfraStructure.h"
#include <thread>
#include <vector>

using namespace std;

namespace ESGI
{
	struct Input : public InfraStructure
	{
		vector<int> inputsPressed;

		bool QuitButtonPressed = false;

		bool Initialize() final;

		void DeInitialize() final;

		void RunUpdate();
		// ce n'est pas une fonction virtuelle !
		thread Update();

		void GetInputs();
	};
}