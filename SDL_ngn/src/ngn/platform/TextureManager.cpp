#include "ngnpch.h"
#include "TextureManager.h"
#include "Window.h"

#include "Texture.h"

namespace ngn
{
	SDL_Texture* TextureManager::LoadFromFile(const char* fileName)
	{
		SDL_Surface* surface = IMG_Load(fileName);
		if (!surface)
		{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load texture %s: %s", fileName, SDL_GetError());
			return nullptr;
		}
		SDL_Texture* texture = SDL_CreateTextureFromSurface(Window::Renderer(), surface);
		SDL_FreeSurface(surface);
		return texture;
	}

	void TextureManager::Render(const Texture& tex)
	{
		SDL_RenderCopyEx(Window::Renderer(), tex.m_texture, &tex.m_srcrect, &tex.m_dstrect, 0.0, NULL, SDL_RendererFlip::SDL_FLIP_NONE);
	}


	//void TextureManager::Render(SDL_Texture* texture)
	//{
	//	SDL_RenderCopyEx(Window::Renderer(), texture, NULL, NULL, 0.0, NULL, SDL_RendererFlip::SDL_FLIP_NONE);
	//}

	//void TextureManager::Render(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dstRect)
	//{
	//	SDL_RenderCopyEx(Window::Renderer(), texture, srcRect, dstRect, 0.0, NULL, SDL_RendererFlip::SDL_FLIP_NONE);
	//}

	//void TextureManager::Render(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dstRect, float angle)
	//{
	//	SDL_RenderCopyEx(Window::Renderer(), texture, srcRect, dstRect, angle, NULL, SDL_RendererFlip::SDL_FLIP_NONE);
	//}

	//void TextureManager::Render(SDL_Texture* texture, SDL_Rect* dstRect, float angle)
	//{
	//	SDL_RenderCopyEx(Window::Renderer(), texture, NULL, dstRect, angle, NULL, SDL_RendererFlip::SDL_FLIP_NONE);
	//}

	//void TextureManager::Render(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dstRect, float angle, SDL_RendererFlip flip)
	//{
	//	SDL_RenderCopyEx(Window::Renderer(), texture, srcRect, dstRect, angle, NULL, flip);
	//}

	void TextureManager::Free(SDL_Texture* texture)
	{
		SDL_DestroyTexture(texture);
	}

}