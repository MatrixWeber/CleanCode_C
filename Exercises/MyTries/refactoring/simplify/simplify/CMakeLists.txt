add_executable(simplify "")
target_sources(simplify
    PRIVATE
        calculator.c
        tests.c
        main.c
        divide_operation.c
        divide_operation_proxy.c
        multiply_operation.c
        minus_operation.c
        plus_operation.c
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/tests.h"
        "${CMAKE_CURRENT_LIST_DIR}/../../test_framework/test_functions.h"
        "${CMAKE_CURRENT_LIST_DIR}/calculator.h"
        "${CMAKE_CURRENT_LIST_DIR}/i_operationable.h"
        "${CMAKE_CURRENT_LIST_DIR}/divide_operation.h"
        "${CMAKE_CURRENT_LIST_DIR}/divide_operation_proxy.h"
        "${CMAKE_CURRENT_LIST_DIR}/multiply_operation.h"
        "${CMAKE_CURRENT_LIST_DIR}/minus_operation.h"
        "${CMAKE_CURRENT_LIST_DIR}/plus_operation.h"
)
    
target_include_directories(simplify
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
