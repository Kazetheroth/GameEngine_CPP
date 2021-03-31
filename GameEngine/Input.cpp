
#include "Input.h"

// pour quitter la boucle : a ne pas utiliser dans une vraie application
#include <conio.h>

#include <iostream>

namespace ESGI {

	vector<int> Input::inputsPressed = {};

	bool Input::Initialize() 
	{
#if defined(_DEBUG)
		m_DebugName = "Input";
#endif
		std::cout << "[Input] initialized\n";
		return true;
	}

	void Input::DeInitialize()
	{
		std::cout << "[Input] deinitialized\n";
	}

	void Input::RunUpdate()
	{
		GetInputs();
	}

	// ce n'est pas une fonction virtuelle !
	thread Input::Update()
	{
		return thread(&Input::RunUpdate, this);
	}

	void Input::GetInputs()
	{
		if (_kbhit())
		{
			int ch = _getch();
			if (ch == 27) {
				QuitButtonPressed = true;
				return;
			}

			inputsPressed.push_back(ch);
		}
	}
}