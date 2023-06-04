add_executable(kiss "")
target_sources(kiss
        PRIVATE
        kiss.c
        calendar.c
        year.c
        month.c
        PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/datehelper.h"
        "${CMAKE_CURRENT_LIST_DIR}/calendar.h"
        "${CMAKE_CURRENT_LIST_DIR}/year.h"
        "${CMAKE_CURRENT_LIST_DIR}/month.h"
)

target_include_directories(kiss
        PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
