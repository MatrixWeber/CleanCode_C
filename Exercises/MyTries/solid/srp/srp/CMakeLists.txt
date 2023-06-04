add_executable(srp "")
target_sources(srp
    PRIVATE
        account.c
        bank.c
        main.c
        logger.c
        my_time.c
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/account.h"
        "${CMAKE_CURRENT_LIST_DIR}/bank.h"
        "${CMAKE_CURRENT_LIST_DIR}/logger.h"
        "${CMAKE_CURRENT_LIST_DIR}/my_time.h"
)

target_include_directories(srp
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
