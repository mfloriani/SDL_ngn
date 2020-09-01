#pragma once

#include "ngn/Core.h"
#include "Component.h"
#include "ngn/platform/NgnTexture.h"

namespace ngn
{
	class NGN_API Sprite : public Component
	{
	public:
		Sprite(NgnTexture texture);
		//Sprite(const Sprite& other);
		//Sprite(Sprite&& other) noexcept;

		virtual ~Sprite() = default;

		inline const NgnTexture& GetTexture() const{ return m_texture; }

	private:
		NgnTexture m_texture;
	};


}