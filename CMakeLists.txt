cmake_minimum_required(VERSION 3.15)
project(algorithms CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

include("conan/Dependencies.cmake")
add_subdirectory("src")
