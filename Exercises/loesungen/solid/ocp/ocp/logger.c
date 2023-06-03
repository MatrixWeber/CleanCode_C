#include "logger.h"
#include <stdio.h>
#include <time.h>

void Log(const char* message) { printf(message); }

void LogDouble(const char* message, const double value)
{
  Log(message);
  printf("%f", value);
  Log("\n");
}

void LogDate(const char* message)
{
  time_t current_time;
  time(&current_time);

  const char* time_string = ctime(&current_time);
  Log(message);
  Log(time_string);
  Log("\n");
}
