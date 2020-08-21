#pragma once

#ifdef NGN_PLATFORM_WINDOWS
	#ifdef NGN_BUILD_DLL
		#define NGN_API __declspec(dllexport)
	#else
		#define NGN_API __declspec(dllimport)
	#endif // NGN_BUILD_DLL
#else
	#error NGN supports only Windows
#endif // NGN_PLATFORM_WINDOWS

constexpr auto WINDOW_WIDTH = 1440;
constexpr auto WINDOW_HEIGHT = 900;

