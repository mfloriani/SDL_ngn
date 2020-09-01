#include "ngnpch.h"
#include "Sprite.h"

namespace ngn
{
	Sprite::Sprite(NgnTexture texture) :
		m_texture(texture)
	{
		NGN_CORE_TRACE("Sprite()");
	}

	//Sprite::Sprite(const Sprite& other) : 
	//	Component(other),
	//	m_texture(other.m_texture)
	//{
	//	NGN_CORE_TRACE("Sprite(&)");
	//}

	//Sprite::Sprite(Sprite&& other) noexcept : 
	//	Component(std::forward<Component>(other)),
	//	m_texture(other.m_texture)
	//{
	//	NGN_CORE_TRACE("Sprite(&&)");
	//	//other.m_texture = nullptr;
	//}
}