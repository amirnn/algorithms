cmake_minimum_required(VERSION 3.15)
project(algorithms CXX)



add_executable(algorithms src/algorithms.cpp src/main.cpp)



install(TARGETS algorithms DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
