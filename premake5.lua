-- First define a workspace
workspace "Game-Engine"
    architecture "ARM64"
    startproject "Sandbox"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Hazel Engine Project (Shared Library)
project "Hazel"
    location "Hazel"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "Off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/Hazel.h"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:macosx"
        defines {
            "HZ_PLATFORM_MAC",
            "HZ_BUILD_DLL"
        }

        buildoptions { 
            "-fvisibility=hidden",
            "-fPIC"
        }

        postbuildcommands {
            "{MKDIR} ../bin/" .. outputdir .. "/Sandbox",
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
        }
    
    filter "configurations:Debug"
        defines "HZ_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "HZ_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HZ_DIST"
        optimize "Full"

    filter {}

-- Sandbox Application Project
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "Off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Hazel",
        "Hazel/src",
        "Hazel/vendor/spdlog/include"
    }

    links {
        "Hazel"
    }

    -- Add library search path
    libdirs {
        "bin/" .. outputdir .. "/Hazel"
    }

    filter "system:macosx"
        defines {
            "HZ_PLATFORM_MAC"
        }

        linkoptions {
            "-rpath @executable_path",
            "-Wl,-rpath,@executable_path"
        }
    
    filter "configurations:Debug"
        defines "HZ_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "HZ_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HZ_DIST"
        optimize "Full"

    filter {}