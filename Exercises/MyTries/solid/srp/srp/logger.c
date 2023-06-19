//
// Created by SW on 04.06.2023.
//

#include <stdio.h>
#include "my_time.h"
#include "logger.h"

void Log_Double(const char *const message, const double value)
{
    printf("%s %f\n", message, value);
}

static void Log_String(const char* message, const char* info)
{
    printf( "%s %s\n", message, info);
}

void Log_WithTimestamp(const char *const message)
{
    const char* time_string = GetTimeString();
    Log_String(message, time_string);
}