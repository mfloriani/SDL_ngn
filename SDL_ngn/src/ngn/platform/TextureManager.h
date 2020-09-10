#pragma once

#include "ngn/Core.h"

namespace ngn
{
	struct Texture;

	class NGN_API TextureManager
	{
	public:
		static SDL_Texture* LoadFromFile(const char* fileName);

		static void Render(const Texture& texture);

		//static void Render(SDL_Texture* texture);
		//static void Render(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dstRect);
		//static void Render(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dstRect, float angle);
		//static void Render(SDL_Texture* texture, SDL_Rect* dstRect, float angle);
		//static void Render(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dstRect, float angle, SDL_RendererFlip flip);
		
		
		static void Free(SDL_Texture* texture);
	};


}