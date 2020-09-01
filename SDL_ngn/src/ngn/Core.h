#pragma once

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

#ifdef NGN_PLATFORM_WINDOWS
	#ifdef NGN_BUILD_DLL
		#define NGN_API __declspec(dllexport)
	#else
		#define NGN_API __declspec(dllimport)
	#endif // NGN_BUILD_DLL
#else
	#error NGN supports only Windows
#endif // NGN_PLATFORM_WINDOWS

constexpr float FPS{ 60.f };
constexpr float FRAME_LENGTH{ 1000.f / FPS };

constexpr size_t COMP_MNGR_INIT_BUFFER{ 1024 };