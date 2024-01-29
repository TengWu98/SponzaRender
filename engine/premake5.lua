-- project Engine
project "SponzaRender"
	-- 项目类型
	kind "ConsoleApp"

	-- 语言：C++
	language "C++"

	-- C++标准 
	cppdialect "C++17"

	staticruntime "on"

	-- 指定输出目录
	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")

	-- 指定中间目录
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	-- 预编译头文件
	pchheader "pch.h"

	-- vs需要包含
	pchsource "source/pch.cpp"

	-- Dependencies
	IncludeDir = {}
	IncludeDir["ImGui"] = "%{wks.location}/engine/3rdparty/imgui"


    -- 收集文件
	files
	{
		-- 加载source目录下的所有.h,.cpp文件
		"source/**.h",
		"source/**.cpp",
	}

	includedirs
	{
		"source",
		"3rdparty/spdlog/include",
		"%{IncludeDir.ImGui}",
	}

    links
	{
		"ImGui",
	}
  
	flags { "NoPCH" }

	-- windows平台
	filter "system:windows"
		systemversion "latest"
		defines
		{
			"SPONZA_RENDER_PLATFORM_WINDOWS",
		}

	-- Debug配置项属性
	filter "configurations:Debug"
		defines "SPONZA_RENDER_DEBUG"
		runtime "Debug"
		symbols "on"

	-- Release配置项属性
	filter "configurations:Release"
		defines "SPONZA_RENDER_RELEASE"
		runtime "Release"
		optimize "on"