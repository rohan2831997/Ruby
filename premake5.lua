workspace "Ruby"
	architecture "x64"

	configurations
	{
		"Debug",
		"Development",
		"Distribution"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "RubyEngine"
	location "RubyEngine"
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
		"%{prj.name}/ThirdParty/spdlog/include",
		"%{prj.name}/src/Ruby"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

	defines
	{
		"R_WINDOWS_PLATFORM",
		"R_BUILD_DLL"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
	}

	filter "configurations:Debug"
	defines "R_DEBUG"
	symbols "On"

	filter "configurations:Development"
	defines "R_DEVELOPMENT"
	optimize "On"

	filter "configurations:Distribution"
	defines "R_DISTRIBUTION"
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
		"%{prj.name}/ThirdParty/spdlog/include",
		"RubyEngine/ThirdParty/spdlog/include",
		"RubyEngine/src"
	}

	links
	{
		"RubyEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

	defines
	{
		"R_WINDOWS_PLATFORM"
		
	}

	filter "configurations:Debug"
	defines "R_DEBUG"
	symbols "On"

	filter "configurations:Development"
	defines "R_DEVELOPMENT"
	optimize "On"

	filter "configurations:Distribution"
	defines "R_DISTRIBUTION"
	optimize "On"