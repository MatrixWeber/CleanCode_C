add_executable(moving_features_between_objects "")
target_sources(moving_features_between_objects
    PRIVATE
        address.c
        address_management.c
        tests.c
        main.c
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/address.h"
        "${CMAKE_CURRENT_LIST_DIR}/tests.h"
        "${CMAKE_CURRENT_LIST_DIR}/../../test_framework/test_functions.h"
        "${CMAKE_CURRENT_LIST_DIR}/address_management.h")
    
target_include_directories(moving_features_between_objects
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
