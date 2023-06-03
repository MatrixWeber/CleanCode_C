cmake_minimum_required(VERSION 3.9)

add_executable("${PROJECT_NAME}" "")
target_sources("${PROJECT_NAME}"
    PRIVATE
        main.c)

target_include_directories("${PROJECT_NAME}"
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")

add_subdirectory(source)
add_subdirectory(test)

