add_executable(simplify "")
target_sources(simplify
    PRIVATE
        calculator.c
        tests.c
        main.c
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/tests.h"
        "${CMAKE_CURRENT_LIST_DIR}/../../test_framework/test_functions.h"
        "${CMAKE_CURRENT_LIST_DIR}/calculator.h")
    
target_include_directories(simplify
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
