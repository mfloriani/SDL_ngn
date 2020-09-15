workspace "SDL_ngn"
	architecture "x86"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

startproject "Sandbox"

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
		"%{prj.name}/common/sdl2/include",
		"%{prj.name}/common/glm"
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
			("{MKDIR} ../bin/" ..outputdir.. "/Sandbox"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
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

project "Sandbox"
	location "Sandbox"
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
		"SDL_ngn/common/sdl2/include",
		"SDL_ngn/common/glm"
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

		postbuildcommands
		{
			("{MKDIR} ../bin/" .. outputdir .. "/%{prj.name}/assets"),
			("{COPY} ./assets ../bin/" .. outputdir .. "/%{prj.name}/assets")
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