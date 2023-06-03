target_sources("${PROJECT_NAME}"
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/test_helpers.h"
        "${CMAKE_CURRENT_LIST_DIR}/test_helpers.c"
        "${CMAKE_CURRENT_LIST_DIR}/tests_counter.c"
        "${CMAKE_CURRENT_LIST_DIR}/tests_counter_limit.c"
        "${CMAKE_CURRENT_LIST_DIR}/tests_range_checker.c"
        "${CMAKE_CURRENT_LIST_DIR}/tests.c"
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/tests.h")
    
target_include_directories("${PROJECT_NAME}"
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
