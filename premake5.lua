workspace "Pop"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Pop"
	location "Pop"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.cpp",
		"%{prj.name}/Source/**.hpp",
		"%{prj.name}/Source/**.h"
	}

	includedirs
	{
		"%{prj.name}/ThirdParty/",
		"%{prj.name}/Source/",
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"POP_PLATFORM_WINDOWS",
			"POP_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "POP_ENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "POP_ENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "POP_ENGINE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox" 
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.cpp",
		"%{prj.name}/Source/**.hpp",
		"%{prj.name}/Source/**.h",
	}

	includedirs
	{
		"Pop/ThirdParty/",
		"Pop/Source/"
	}

	links
	{
		"Pop"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"POP_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "POP_ENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "POP_ENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "POP_ENGINE_DIST"
		optimize "On"
