add_executable(smells "")
target_sources(smells
    PRIVATE
        address.c
        address_management.c
        main.c
        console.c
        application.c
        disk.c
        null_object.c
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/address.h"
        "${CMAKE_CURRENT_LIST_DIR}/address_management.h"
        "${CMAKE_CURRENT_LIST_DIR}/console.h"
        "${CMAKE_CURRENT_LIST_DIR}/disk.h"
        "${CMAKE_CURRENT_LIST_DIR}/application.h"
        "${CMAKE_CURRENT_LIST_DIR}/null_object.h"
)
    
target_include_directories(smells
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
