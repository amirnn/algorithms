cmake_minimum_required(VERSION 3.31.0)

project(algorithms-assignements VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../../cpp" "${CMAKE_CURRENT_BINARY_DIR}/libs")

add_executable(percolation)
target_sources(percolation PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/w-1-percolation/main.cpp")
target_link_libraries(percolation PRIVATE dsa)

add_executable(randomized-queue)
target_sources(randomized-queue PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/w-2-randomized-queue/main.cpp")
target_link_libraries(randomized-queue PRIVATE dsa)

add_executable(collinear-points)
target_sources(collinear-points PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/w-3-collinear-points/main.cpp")
target_link_libraries(collinear-points PRIVATE dsa)

add_executable(eight-puzzle)
target_sources(eight-puzzle PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/w-4-eight-puzzle/main.cpp")
target_link_libraries(eight-puzzle PRIVATE dsa)

add_executable(kd-tree)
target_sources(kd-tree PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/w-5-kd-tree/main.cpp")
target_link_libraries(kd-tree PRIVATE dsa)