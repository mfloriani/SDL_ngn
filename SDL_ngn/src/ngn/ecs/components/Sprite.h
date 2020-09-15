#pragma once

#include "ngn/Core.h"
#include "Component.h"
#include "ngn/platform/Texture.h"

namespace ngn
{
	struct NGN_API Sprite : public Component
	{
	public:
		Sprite(Texture* texture);
		
		Sprite(Sprite&&) = default;
		Sprite& operator=(Sprite&&) = default;

		virtual ~Sprite() = default;
		
		Sprite(const Sprite&) = delete;
		Sprite& operator=(const Sprite&) = delete;

		inline void SetTo(int x, int y) { m_dstRect.x = x; m_dstRect.y = y; }

		inline Texture* GetTexture() { return m_texture; }
		inline SDL_Rect& GetSourceRect() { return m_srcRect; }
		inline SDL_Rect& GetDestinationRect() { return m_dstRect; }

	public:
		Texture* m_texture;
		SDL_Rect m_srcRect;
		SDL_Rect m_dstRect;
	};


}