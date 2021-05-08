cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_FLAGS "-std=c++0x -Wall -Wextra -O3")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin/)
project(project)

include_directories(&{SDL2_INCLUDE_DIRS})
include_directories(../include/)

add_executable(Terminal
        screen.cpp
        main.cpp)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(Terminal ${SDL2_LIBRARIES})