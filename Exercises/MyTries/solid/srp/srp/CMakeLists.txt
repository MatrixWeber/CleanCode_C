add_executable(srp "")
target_sources(srp
    PRIVATE
        account.c
        bank.c
        main.c
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/account.h"
        "${CMAKE_CURRENT_LIST_DIR}/bank.h")
    
target_include_directories(srp
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
