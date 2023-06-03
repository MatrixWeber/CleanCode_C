add_executable(composing_methods "")
target_sources(composing_methods
    PRIVATE
        counter.c
        counter_app.c
        tests.c
        main.c
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/counter.h"
        "${CMAKE_CURRENT_LIST_DIR}/counter_app.h"
        "${CMAKE_CURRENT_LIST_DIR}/../../test_framework/test_functions.h"
        "${CMAKE_CURRENT_LIST_DIR}/tests.h")
    
target_include_directories(composing_methods
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
