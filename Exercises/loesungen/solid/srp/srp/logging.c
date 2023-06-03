#include "logging.h"
#include <stdio.h>
#include <time.h>

void WriteLog(const char* message, double data)
{
  printf("%s %f\n", message, data);
}

void WriteLog_S(const char* message, const char* info)
{
  printf("%s %s\n", message, info);
}

void WriteLog_Date(const char* message)
{
  time_t current_time;
  time(&current_time);

  const char* time_string = ctime(&current_time);
  WriteLog_S(message, time_string);
}
