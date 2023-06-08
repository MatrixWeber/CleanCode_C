#include "counter_app.h"
#include "counter.h"

#define NUMBER_OF_COUNTERS_1 3
#define NUMBER_OF_COUNTERS_2 2
#define NUMBER_OF_LOOPS 3

void InitCounters(Counter counters[], const int number, const int initial_value)
{
  for (int i = 0; i < number; i++) {
    Counter_InitValue(&counters[i], initial_value);
  }
}

void ShowCounters(Counter counters[], const int number, FILE* file,
                  const char* message)
{
  fprintf(file, "%s", message);
  for (int i = 0; i < number; i++) {
    fprintf(file, "%d\n", Counter_GetValue(&counters[i]));
  }
}

void CountCounters(Counter counters[], const int number, const int step)
{
  for (int i = 0; i < number; i++) {
    Counter_Count(&counters[i], step);
  }
}

void CountAllCounters(Counter counters[], const int number, const int step,
                      const int loops)
{
  for (int i = 0; i < loops; i++) {
    CountCounters(counters, number, step);
  }
}

void UseCounter(FILE* file)
{
  Counter counters_1[NUMBER_OF_COUNTERS_1];
  Counter counters_2[NUMBER_OF_COUNTERS_2];

  InitCounters(counters_1, NUMBER_OF_COUNTERS_1, 0);
  InitCounters(counters_2, NUMBER_OF_COUNTERS_2, 10);

  ShowCounters(counters_1, NUMBER_OF_COUNTERS_1, file, "\nVector 1:\n");
  ShowCounters(counters_2, NUMBER_OF_COUNTERS_2, file, "\nVector 2:\n");

  CountAllCounters(counters_1, NUMBER_OF_COUNTERS_1, 1, NUMBER_OF_LOOPS);
  CountAllCounters(counters_2, NUMBER_OF_COUNTERS_2, -1, NUMBER_OF_LOOPS);

  ShowCounters(counters_1, NUMBER_OF_COUNTERS_1, file, "\nVector 1:\n");
  ShowCounters(counters_2, NUMBER_OF_COUNTERS_2, file, "\nVector 2:\n");

  fprintf(file, "\n------------------------------------\n\n");
}
