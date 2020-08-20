#pragma once

#include "Core.h"

namespace ngn
{
	class NGN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}