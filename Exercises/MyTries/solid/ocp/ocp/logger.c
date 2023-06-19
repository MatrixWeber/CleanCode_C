#include "logger.h"
#include <stdio.h>
#include <time.h>

void LogText(const char *const message) { printf("%s", message); }

void LogDouble(const double value) { printf("%f", value); }

void LogDate(const char *message) {
    time_t current_time;
    time(&current_time);

    const char *time_string = ctime(&current_time);
    LogText(message);
    LogText(time_string);
    LogText("\n");
}
