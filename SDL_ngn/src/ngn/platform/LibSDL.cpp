#include "ngnpch.h"
#include "LibSDL.h"
#include "ngn/platform/Renderer.h"

namespace ngn
{
	LibSDL::LibSDL()
	{

	}

	LibSDL::~LibSDL()
	{
		
	}

	bool LibSDL::Init()
	{
		SDL_SetMainReady();
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			NGN_CORE_CRITICAL("Failed to initialize SDL! SDL_Error: {0}", SDL_GetError());
			return false;
		}

		if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		{
			NGN_CORE_CRITICAL("Failed to initialize SDL_IMAGE! SDL_Error: {0}", IMG_GetError());
			return false;
		}
		if (TTF_Init() == -1)
		{
			NGN_CORE_CRITICAL("Failed to initialize SDL_TTF! SDL_Error: {0}", TTF_GetError());
			return false;
		}
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			NGN_CORE_CRITICAL("Failed to initialize SDL_MIXER! SDL_Error: {0}", Mix_GetError());
			return false;
		}

		return true;
	}

	void LibSDL::Quit()
	{
		Renderer::Instance().Quit();
		Mix_Quit();
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
	}

}