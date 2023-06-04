//
// Created by SW on 04.06.2023.
//

#include <stdio.h>
#include "my_time.h"
#include "logger.h"

void WriteLog(const char* message, double data)
{
    printf( "%s %f\n", message, data);
}

static void WriteLog_S(const char* message, const char* info)
{
    printf( "%s %s\n", message, info);
}

void WriteLog_WithTimestamp(const char* message)
{
    const char* time_string = GetTimeString();
    WriteLog_S(message, time_string);
}