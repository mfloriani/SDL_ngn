#pragma once

#include "ngn/Core.h"
#include "ngn/Input.h"

namespace ngn
{

	class SDLInput : public Input
	{
	public:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<int, int> GetMousePositionImpl() override;
	};

}