add_executable(ocp "")
target_sources(ocp
    PRIVATE
        account.c
        bank.c
        logger.c
        main.c
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/account.h"
        "${CMAKE_CURRENT_LIST_DIR}/bank.h"
        "${CMAKE_CURRENT_LIST_DIR}/logger.h")
    
target_include_directories(ocp
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
