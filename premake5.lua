-----------------------------workspace---------------------------------------
workspace "ToyEngine"
	architecture "x64"
	startproject "SandBox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
-----------------------------------------------------------------------------



------------------------------projections------------------------------------
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
windowsdkversion = "10.0.17763.0"

project "Engine"
	location "Engine"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion (windowsdkversion)

		defines
		{
			"TOY_PLATFORM_WINDOWS",
			"TOY_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}

		filter "configurations:Debug"
			defines "_Debug"
			symbols "On"

		filter "configurations:Release"
			defines "_Release"
			optimize "On"

		filter "configurations:Dist"
			defines "_Dist"
			optimize "On"
		

project "SandBox"
	location "SandBox"
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
		"Engine/vendor/spdlog/include",
		"Engine/src"
	}

	links
	{
		"Engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion (windowsdkversion)

		defines
		{
			"TOY_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "_Debug"
			symbols "On"

		filter "configurations:Release"
			defines "_Release"
			optimize "On"

		filter "configurations:Dist"
			defines "_Dist"
			optimize "On"