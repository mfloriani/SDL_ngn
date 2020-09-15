#pragma once
#include "ngnpch.h"
#include "ngn/Core.h"
#include "Renderer.h"

namespace ngn
{
	class NGN_API TextureUtil
	{
	public:
		static SDL_Texture* Load(const char* filePath)
		{
			SDL_Surface* surface = IMG_Load(filePath);
			if (!surface)
			{
				SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load texture %s: %s", filePath, SDL_GetError());
			}
			auto texture = SDL_CreateTextureFromSurface(SDLRenderer, surface);
			SDL_FreeSurface(surface);
			return texture;
		}

		inline static void Free(SDL_Texture* tex) 
		{
			SDL_DestroyTexture(tex); 
		};

		inline static void GetSize(SDL_Texture* tex, int* x, int* y)
		{
			SDL_QueryTexture(tex, NULL, NULL, x, y);
		}
	};
}