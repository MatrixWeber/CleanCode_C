add_executable(kiss "")
target_sources(kiss
    PRIVATE
        kiss.c
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/datehelper.h")
    
target_include_directories(kiss
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}")
