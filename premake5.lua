project "SQLite-CPP"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp",
		"include/**.h"
	}

	includedirs
	{
		"include",
        	"sqlite3"
	}

	defines
	{
		"SQLITE_OMIT_LOAD_EXTENSION"
	}
 

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++20"
		staticruntime "off"

	filter "system:linux"
		pic "On"
		systemversion "latest"
		cppdialect "C++20"
		staticruntime "off"
    
    filter "system:macosx"
		cppdialect "c++20"
		staticruntime "On"
    
        links{
            "pthread",
            "dl"
        }


	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
