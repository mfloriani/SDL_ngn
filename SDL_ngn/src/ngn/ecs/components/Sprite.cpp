#include "ngnpch.h"
#include "Sprite.h"

namespace ngn
{
	Sprite::Sprite(Texture* tex) : 
		m_texture(tex),
		m_srcRect({ 0, 0, 0, 0}),
		m_dstRect({0, 0, 0, 0})
	{
		m_srcRect.w = tex->GetWidth();
		m_srcRect.h = tex->GetHeight();

		m_dstRect.w = tex->GetWidth();
		m_dstRect.h = tex->GetHeight();
	}

}