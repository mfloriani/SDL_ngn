#pragma once

#include "ngn/Core.h"
#include "Component.h"
#include "ngn/platform/Texture.h"

namespace ngn
{
	struct NGN_API Sprite : public Component
	{
	public:
		Sprite(Texture texture);
		
		Sprite(Sprite&&) = default;
		Sprite& operator=(Sprite&&) = default;

		virtual ~Sprite() = default;
		
		Sprite(const Sprite&) = delete;
		Sprite& operator=(const Sprite&) = delete;

	public:
		Texture texture;
	};


}