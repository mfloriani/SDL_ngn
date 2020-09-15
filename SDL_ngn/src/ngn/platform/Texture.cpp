#include "ngnpch.h"
#include "Texture.h"
#include "TextureUtil.h"

namespace ngn
{
	Texture::Texture(std::string filePath) : m_texture(nullptr)
	{
		m_texture = TextureUtil::Load(filePath.c_str());
		TextureUtil::GetSize(m_texture, &m_width, &m_height);
	}
	
	Texture::~Texture()
	{
		TextureUtil::Free(m_texture);
	}

	
}