cmake_minimum_required(VERSION 3.15)
project(algorithms CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include("conan/Dependencies.cmake")
add_subdirectory("src")
