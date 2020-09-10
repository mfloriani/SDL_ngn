#include "ngnpch.h"
#include "SDLInput.h"

namespace ngn
{
	Input* Input::s_instance = new SDLInput();

	bool SDLInput::IsKeyPressedImpl(int keycode)
	{
		SDL_PumpEvents();
		auto state = SDL_GetKeyboardState(NULL);
		if (state[SDL_GetScancodeFromKey(keycode)])
		{
			return true;
		}
		return false;
	}

	bool SDLInput::IsMouseButtonPressedImpl(int button)
	{
		SDL_PumpEvents();
		auto state = SDL_GetMouseState(NULL, NULL);
		if (state & SDL_BUTTON(button))
		{
			return true;
		}
		return false;
	}

	std::pair<int, int> SDLInput::GetMousePositionImpl()
	{
		SDL_PumpEvents();
		int x, y;
		SDL_GetMouseState(&x, &y);
		return { x, y };
	}

}