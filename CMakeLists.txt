cmake_minimum_required(VERSION 3.15)
project(algorithms CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(mergeSort src/algorithms/MergeSort.cc)

add_executable(algorithms
        src/main.cc
        src/algorithms/Algorithms.cc
        )



install(TARGETS algorithms DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
