add_executable(ocp "")
target_sources(ocp
    PRIVATE
        account.c
        bank.c
        logger.c
        main.c
        interest_calculator.c
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/account.h"
        "${CMAKE_CURRENT_LIST_DIR}/account_type.h"
        "${CMAKE_CURRENT_LIST_DIR}/bank.h"
        "${CMAKE_CURRENT_LIST_DIR}/logger.h"
        "${CMAKE_CURRENT_LIST_DIR}/interest_calculator.h"
)
    
target_include_directories(ocp
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
