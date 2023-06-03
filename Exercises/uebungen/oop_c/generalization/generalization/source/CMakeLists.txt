target_sources("${PROJECT_NAME}"
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/counter.c"
        "${CMAKE_CURRENT_LIST_DIR}/range_checker.c"
        "${CMAKE_CURRENT_LIST_DIR}/down_counter.c"
        "${CMAKE_CURRENT_LIST_DIR}/up_counter.c"
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/counter.h"
        "${CMAKE_CURRENT_LIST_DIR}/range_checker.h"
        "${CMAKE_CURRENT_LIST_DIR}/down_counter.h"
        "${CMAKE_CURRENT_LIST_DIR}/up_counter.h")
    
target_include_directories("${PROJECT_NAME}"
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
