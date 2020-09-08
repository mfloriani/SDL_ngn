#pragma once

#include "ngn/Core.h"
#include "Component.h"
#include "ngn/platform/NgnTexture.h"

namespace ngn
{
	struct NGN_API Sprite : public Component
	{
	public:
		Sprite(NgnTexture texture);
		
		Sprite(Sprite&&) = default;
		Sprite& operator=(Sprite&&) = default;

		virtual ~Sprite() = default;
		
		Sprite(const Sprite&) = delete;
		Sprite& operator=(const Sprite&) = delete;

	public:
		NgnTexture texture;
	};


}