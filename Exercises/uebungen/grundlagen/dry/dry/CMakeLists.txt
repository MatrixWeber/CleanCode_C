add_executable(dry "")
target_sources(dry
    PRIVATE
        account.c
        bank.c
        main.c
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/account.h"
        "${CMAKE_CURRENT_LIST_DIR}/bank.h")
    
target_include_directories(dry
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
