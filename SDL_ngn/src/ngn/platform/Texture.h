#pragma once

#include "ngn/Core.h"

#include <sdl2/SDL.h>

namespace ngn
{


	struct NGN_API Texture
	{
		SDL_Texture* m_texture{nullptr};
		SDL_Rect     m_srcrect{ 0,0,0,0 };
		SDL_Rect     m_dstrect{ 0,0,0,0 };
	};


}