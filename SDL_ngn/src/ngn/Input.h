#pragma once

#include "Core.h"

namespace ngn
{

	class NGN_API Input
	{
	public:
		inline static bool IsKeyPressed(int keycode) { return s_instance->IsKeyPressedImpl(keycode); }
		inline static bool IsMouseButtonPressed(int button) { return s_instance->IsMouseButtonPressedImpl(button); }
		inline static std::pair<int, int> GetMousePosition() { return s_instance->GetMousePositionImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<int, int> GetMousePositionImpl() = 0;

	private:
		static Input* s_instance;
	};

}