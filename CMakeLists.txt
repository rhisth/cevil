cmake_minimum_required (VERSION 3.5)

project ("nohrin hexagon simulator")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "/Wall /Od /EHsc /Zc:__cplusplus")
set(CMAKE_CXX_FLAGS_RELEASE "/W0 /O2 /EHsc /Zc:__cplusplus")

set(OUT_DIR "../../../")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUT_DIR}/tmp")
set(CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY "${OUT_DIR}/tmp")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUT_DIR}/tmp")
set(CMAKE_PDB_OUTPUT_DIRECTORY "${OUT_DIR}/tmp")

set (Game "Game")

add_executable (${Game} "main.cpp")

set_target_properties(${Game} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/__game/engine")
