#pragma once

#include "ngnpch.h"
#include "ngn/Core.h"

namespace ngn
{
	class NGN_API LibSDL
	{
	public:
		LibSDL();
		~LibSDL();

		static bool Init();
		static void Quit();

	};
}