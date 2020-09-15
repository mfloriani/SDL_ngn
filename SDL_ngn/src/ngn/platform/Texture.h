#pragma once

#include "ngn/Core.h"
#include "AssetManager.h"

namespace ngn
{
	class NGN_API Texture
	{
	public:
		Texture(std::string filePath);
		~Texture();

		inline SDL_Texture* GetSDLTexture() const { return m_texture; }
		inline int GetWidth() const { return m_width; }
		inline int GetHeight() const { return m_height; }

	private:
		SDL_Texture* m_texture;
		int          m_width;
		int          m_height;
		
	};
}