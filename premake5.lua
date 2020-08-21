workspace "SDL_ngn"
	architecture "x86"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SDL_ngn"
	location "SDL_ngn"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ngnpch.h"
	pchsource "SDL_ngn/src/ngnpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/common/spdlog/include",
		"%{prj.name}/common/sdl2/include"
	}

	libdirs
	{
		"%{prj.name}/common/sdl2/lib/x86"
	}

	links
	{
		"SDL2",
		"SDL2main",
		"SDL2_image",
		"SDL2_mixer",
		"SDL2_ttf",
		"SDL2_net"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NGN_PLATFORM_WINDOWS",
			"NGN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{MKDIR} ../bin/" ..outputdir.. "/BattleShip"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/BattleShip")
		}

	filter "configurations:Debug"
		defines "NGN_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "NGN_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "NGN_DIST"
		buildoptions "/MD"
		optimize "On"

project "BattleShip"
	location "BattleShip"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"SDL_ngn/src",
		"SDL_ngn/common/spdlog/include",
		"SDL_ngn/common/sdl2/include"
	}

	links
	{
		"SDL_ngn"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NGN_PLATFORM_WINDOWS"		
		}

	filter "configurations:Debug"
		defines "NGN_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "NGN_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "NGN_DIST"
		buildoptions "/MD"
		optimize "On"