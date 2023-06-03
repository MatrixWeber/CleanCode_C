add_executable(dry "")
target_sources(dry
    PRIVATE
        disk.c
        console.c
        account.c
        bank.c
        main.c
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/disk.h"
        "${CMAKE_CURRENT_LIST_DIR}/console.h"
        "${CMAKE_CURRENT_LIST_DIR}/account.h"
        "${CMAKE_CURRENT_LIST_DIR}/bank.h")
    
target_include_directories(dry
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
