#include "tests.h"
#include <string.h>
#include "../../test_framework/test_functions.h"
#include "counter.h"
#include "counter_app.h"

#define MAX_BUFFER_SIZE 256

void CountHelper(Counter* counter, const int loops, const int step)
{
  for (int i = 0; i < loops; i++) {
    Counter_Count(counter, step);
  }
}

TEST(TestCounterInit1)
{
  const int expected = 0;
  Counter counter;
  Counter_Init(&counter);

  ASSERT(Counter_GetValue(&counter) == expected,
         "Counter initialization failed");
}

TEST(TestCounterInit2)
{
  const int expected = 42;
  Counter counter;
  Counter_InitValue(&counter, expected);

  ASSERT(Counter_GetValue(&counter) == expected,
         "Counter initialization failed");
}

TEST(TestCounterInit3)
{
  const int expected = 2;
  const int expected_max = 42;
  Counter counter;
  Counter_InitValueMax(&counter, expected, expected_max);

  ASSERT(Counter_GetValue(&counter) == expected,
         "Counter initialization failed");
  ASSERT(counter.max_value == expected_max, "Counter initialization failed");
}

TEST(TestCounterCount1)
{
  const int expected = 4;
  const int step = 1;
  Counter counter;
  Counter_Init(&counter);

  CountHelper(&counter, expected, step);
  ASSERT_INT(Counter_GetValue(&counter), expected);
}

TEST(TestCounterCount2)
{
  const int init_value = 10;
  const int expected = 4;
  const int step = -1;
  Counter counter;
  Counter_InitValue(&counter, init_value);

  CountHelper(&counter, init_value - expected, step);
  ASSERT_INT(Counter_GetValue(&counter), expected);
}

TEST(TestCounterSetValue)
{
  const int expected = 4;
  Counter counter;
  Counter_SetValue(&counter, expected);
  ASSERT_INT(Counter_GetValue(&counter), expected);
}

TEST(TestCounterOverflow)
{
  const int steps = 6;
  const int max = 4;
  const int expected = steps % max;
  Counter counter;
  Counter_InitValueMax(&counter, 0, max);

  CountHelper(&counter, steps, 1);
  ASSERT_INT(Counter_GetValue(&counter), expected);
}

const char* expected_output[] = {
    "\n",          "Vector 1:\n", "0\n",  "0\n",         "0\n",         "\n",
    "Vector 2:\n", "10\n",        "10\n", "\n",          "Vector 1:\n", "3\n",
    "3\n",         "3\n",         "\n",   "Vector 2:\n", "7\n",         "7\n"};

const int kExpectedOutputLength = sizeof(expected_output) / sizeof(char*);

#define TEST_FILE_NAME "test_output"

TEST(TestCounterUsage)
{
  FILE* test_file = fopen(TEST_FILE_NAME, "w");

  UseCounter(test_file);
  fclose(test_file);

  test_file = fopen(TEST_FILE_NAME, "r");

  char buffer[MAX_BUFFER_SIZE];

  for (int i = 0; i < kExpectedOutputLength; i++) {
    fgets(buffer, MAX_BUFFER_SIZE, test_file);
    const int result = strcmp(buffer, expected_output[i]);
    ASSERT(result == 0, "Counter usage failure");
  }

  fclose(test_file);
}

TEST_SUITE(TestCounter)
{
  RUN_TEST(TestCounterInit1);
  RUN_TEST(TestCounterInit2);
  RUN_TEST(TestCounterInit3);
  RUN_TEST(TestCounterCount1);
  RUN_TEST(TestCounterCount2);
  RUN_TEST(TestCounterSetValue);
  RUN_TEST(TestCounterOverflow);
  RUN_TEST(TestCounterUsage);
}

void RunTests() { RUN_TEST_SUITE(TestCounter); }
