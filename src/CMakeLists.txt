# src

add_subdirectory("intro2algorithms")


# add_executable(main algorithms/Algorithms.cc main.cc)

install(TARGETS main DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )