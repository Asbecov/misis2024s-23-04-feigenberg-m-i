cmake_minimum_required(VERSION 3.15)

project(misis2024s VERSION 1.1.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_GENERATOR Ninja)

set(ADD_CODESORCES 0 CACHE BOOL "Add CodeForces directory to the build")

if (ADD_CODESORCES)
	add_subdirectory(prj.codeforces)
endif ()

add_subdirectory(prj.lab)

add_subdirectory(prj.test)
