// Copyright 2018 MicroConsult GmbH
#ifndef TEST_FUNCTIONS_H_
#define TEST_FUNCTIONS_H_

#include <stdio.h>

static char test_message_buffer[256];

#define TEST(fx) static void fx(const char** message)

#define TEST_SUITE(fx) void fx(int* tests_total, int* tests_successful)

#define RUN_TEST(test)                                 \
  do {                                                 \
    const char* message = 0;                                 \
    ++*tests_total;                                    \
    test(&message);                                    \
    if (message) {                                     \
      printf("--- ERROR (%s): %s \n", #test, message); \
    } else {                                           \
      ++*tests_successful;                             \
      printf("+++ passed: %s\n", #test);               \
    }                                                  \
  } while (0)

#define RUN_TEST_SUITE(test_suite)                                        \
  do {                                                                    \
    int tests_total = 0;                                                  \
    int tests_successful = 0;                                             \
    test_suite(&tests_total, &tests_successful);                          \
    printf("-----------------------------------------------\n");          \
    if (tests_successful == tests_total) {                                \
      printf("+ Test Suite '%s': all %d tests passed\n\n", #test_suite,   \
             tests_total);                                                \
    } else {                                                              \
      printf("- Test Suite '%s': %d of %d tests passed\n\n", #test_suite, \
             tests_successful, tests_total);                              \
    }                                                                     \
  } while (0)

#define ASSERT(test, error_message) \
  do {                              \
    if (test) {                     \
      *message = 0;                 \
    } else {                        \
      *message = error_message;     \
      return;                       \
    }                               \
  } while (0)

#define ASSERT_INT(value, expected)                                      \
  do {                                                                   \
    if (value == expected) {                                             \
      *message = 0;                                                      \
    } else {                                                             \
      sprintf(test_message_buffer,                                       \
              "Wrong value - expected: %d, current value: %d", expected, \
              value);                                                    \
      *message = test_message_buffer;                                    \
      return;                                                            \
    }                                                                    \
  } while (0)

#endif  // TEST_FUNCTIONS_H_
