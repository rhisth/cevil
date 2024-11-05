# Replace paths to SDL2 with your own and add this file to .gitignore in further commits. #

cmake_minimum_required (VERSION 3.5)

project ("cevil")

if (WIN32)
	set(debug "/Wall /Od /EHsc /Zc:__cplusplus")
	set(release "/W0 /O2 /EHsc /Zc:__cplusplus")
	set(gui "/SUBSYSTEM:WINDOWS")
	set(dll "/DLL")
elseif (UNIX)
	set(debug "-Wall -Og -g")
	set(release "-O2 -DNDEBUG")
	set(gui "-Wl,-subsystem,windows")
	set(dll "-shared")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG ${debug})
set(CMAKE_CXX_FLAGS_RELEASE ${release})

set(OUT_DIR "../../../")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUT_DIR}/tmp")
set(CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY "${OUT_DIR}/tmp")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUT_DIR}/tmp")
set(CMAKE_PDB_OUTPUT_DIRECTORY "${OUT_DIR}/tmp")

set (Game "Game")
set (modloader "oddmod")

add_library(${modloader} SHARED "modloader.cpp")
add_executable (${Game} "main.cpp")

target_link_options(${Game} PRIVATE
	${gui}
)
target_link_options(${modloader} PRIVATE
	${dll}
)
include_directories(
	"D:/DIMA/ALL/SDK/SDL2/include"
)
target_link_libraries(${Game} PUBLIC
	${modloader}
	"D:/DIMA/ALL/SDK/SDL2/lib/x64/SDL2.lib"
	"D:/DIMA/ALL/SDK/SDL2/lib/x64/SDL2main.lib"
	"D:/DIMA/ALL/SDK/SDL2/lib/x64/SDL2_image.lib"
	"D:/DIMA/ALL/SDK/SDL2/lib/x64/SDL2_mixer.lib"
	"D:/DIMA/ALL/SDK/SDL2/lib/x64/SDL2_ttf.lib"
)
set_target_properties(${Game} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/__game/engine")
set_target_properties(${modloader} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/__game/engine")