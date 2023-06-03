#include "counter_app.h"
#include "counter.h"

void UseCounter(FILE* file)
{
  Counter counters_1[3];
  Counter counters_2[2];

  unsigned int loop_value = 0;

  for (loop_value = 0; loop_value < 3; loop_value++) {
    Counter_Init(&counters_1[loop_value]);
  }

  for (loop_value = 0; loop_value < 2; loop_value++) {
    Counter_InitValue(&counters_2[loop_value], 10);
  }

  fprintf(file, "\nVector 1:\n");
  for (loop_value = 0; loop_value < 3; loop_value++) {
    fprintf(file, "%d\n", Counter_GetValue(&counters_1[loop_value]));
  }

  fprintf(file, "\nVector 2:\n");
  for (loop_value = 0; loop_value < 2; loop_value++) {
    fprintf(file, "%d\n", Counter_GetValue(&counters_2[loop_value]));
  }

  int outer_loop_value = 0;
  for (outer_loop_value = 0; outer_loop_value < 3; outer_loop_value++) {
    for (loop_value = 0; loop_value < 3; loop_value++) {
      Counter_Count(&counters_1[loop_value], 1);
    }

    for (loop_value = 0; loop_value < 2; loop_value++) {
      Counter_Count(&counters_2[loop_value], -1);
    }
  }

  fprintf(file, "\nVector 1:\n");
  for (loop_value = 0; loop_value < 3; loop_value++) {
    fprintf(file, "%d\n", Counter_GetValue(&counters_1[loop_value]));
  }

  fprintf(file, "\nVector 2:\n");
  for (loop_value = 0; loop_value < 2; loop_value++) {
    fprintf(file, "%d\n", Counter_GetValue(&counters_2[loop_value]));
  }

  fprintf(file, "\n------------------------------------\n\n");
}
