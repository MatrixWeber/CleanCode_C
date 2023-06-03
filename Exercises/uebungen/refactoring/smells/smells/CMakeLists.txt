add_executable(smells "")
target_sources(smells
    PRIVATE
        address.c
        address_management.c
        main.c
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/address.h"
        "${CMAKE_CURRENT_LIST_DIR}/address_management.h")
    
target_include_directories(smells
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
