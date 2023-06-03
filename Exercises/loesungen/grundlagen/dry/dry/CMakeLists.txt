add_executable(dry "")
target_sources(dry
    PRIVATE
        account.c
        bank.c
        tools.c
        main.c
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/account.h"
        "${CMAKE_CURRENT_LIST_DIR}/bank.h"
        "${CMAKE_CURRENT_LIST_DIR}/tools.h")
    
target_include_directories(dry
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
