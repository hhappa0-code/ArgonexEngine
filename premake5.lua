workspace "Argonex"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Argonex"
    location "Argonex"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ARGONEX_PLATFORM_WINDOWS",
            "ARGONEX_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        buildoptions { "/utf-8" }
        defines "ARGONEX_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        buildoptions { "/utf-8" }
        defines "ARGONEX_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        buildoptions { "/utf-8" }
        defines "ARGONEX_DEBUG"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/vendor/spdlog/include",
        "Argonex/src"
    }

    links {
        "Argonex"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ARGONEX_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        buildoptions { "/utf-8" }
        defines "ARGONEX_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        buildoptions { "/utf-8" }
        defines "ARGONEX_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        buildoptions { "/utf-8" }
        defines "ARGONEX_DIST"
        optimize "On"