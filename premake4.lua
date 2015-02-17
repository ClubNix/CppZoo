solution "CppZoo"
	configurations ""
	project "cppzoo"
	kind "ConsoleApp"
	language "C++"
	files({ "src/*.h", "src/*.cpp" })
	--includedirs({"/", "includes"})

	flags({"Symbols", "ExtraWarnings"})
	links({"sfml-graphics", "sfml-window", "sfml-system"})
	--libdirs({"Driver/"})

	buildoptions({"-std=c++11","-Wextra"})
	linkoptions({"-std=c++11"})
