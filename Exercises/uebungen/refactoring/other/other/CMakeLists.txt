add_executable(other "")
target_sources(other
    PRIVATE
        bubble_sort.c
        tests.c
        main.c
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/bubble_sort.h"
        "${CMAKE_CURRENT_LIST_DIR}/../../test_framework/test_functions.h"
        "${CMAKE_CURRENT_LIST_DIR}/tests.h")
    
target_include_directories(other
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
