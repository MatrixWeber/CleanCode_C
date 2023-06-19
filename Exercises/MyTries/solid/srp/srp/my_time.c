//
// Created by SW on 04.06.2023.
//

#include <time.h>

const char* GetTimeString()
{
    time_t current_time;
    time(&current_time);

    const char* time_string = ctime(&current_time);
    return time_string;
}