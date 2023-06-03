// Copyright 2018 MicroConsult GmbH
#include "test/tests.h"

#ifdef ENABLE_TESTS

#include <limits.h>
#include "../../test_framework/test_functions.h"
#include "source/down_counter.h"

static void DownCountHelper(DownCounter* base, const int loops) {
  for (int i = 0; i < loops; i++) {
      DownCounter_Count(base);
  }
}

TEST(Test_DownCounter_Init1) {
  const int lower_limit = -5;
  const int upper_limit = 42;
  const int expected = upper_limit;

  DownCounter base;
  DownCounter_Init(&base, lower_limit, upper_limit);

  ASSERT(Counter_GetValue(&base.base) == expected,
         "Counter initialization failed");
}

TEST(Test_DownCounter_Init2) {
  const int lower_limit = 23;
  const int upper_limit = 42;
  const int expected = upper_limit;

  DownCounter base;
  DownCounter_Init(&base, lower_limit, upper_limit);

  ASSERT(Counter_GetValue(&base.base) == expected,
         "Counter initialization failed");
}

TEST(Test_DownCounter_Init3) {
  const int lower_limit = 23;
  const int upper_limit = 2;
  const int expected = INT_MAX;

  DownCounter base;
  DownCounter_Init(&base, lower_limit, upper_limit);

  ASSERT(Counter_GetValue(&base.base) == expected,
         "Counter initialization failed");
}

TEST(Test_DownCounter_Count1) {
  const int lower_limit = 0;
  const int upper_limit = 59;
  const int expected = 4;

  DownCounter base;
  DownCounter_Init(&base, lower_limit, upper_limit);

  DownCountHelper(&base, expected);

  ASSERT_INT(Counter_GetValue(&base.base), upper_limit - expected);
}

TEST(Test_DownCounter_Count2) {
  const int lower_limit = 0;
  const int upper_limit = 59;
  const int expected = 4;

  DownCounter base;
  DownCounter_Init(&base, lower_limit, upper_limit);

  DownCountHelper(&base, expected + (upper_limit + 1));

  ASSERT_INT(Counter_GetValue(&base.base), upper_limit - expected);
}

TEST(Test_DownCounter_Count3) {
  const int lower_limit = 0;
  const int upper_limit = 59;
  const int expected = 4;

  DownCounter base;
  DownCounter_Init(&base, lower_limit, upper_limit);

  DownCountHelper(&base, expected + (3 * (upper_limit + 1)));

  ASSERT_INT(Counter_GetValue(&base.base), upper_limit - expected);
}

TEST_SUITE(Test_DownCounter) {
  RUN_TEST(Test_DownCounter_Init1);
  RUN_TEST(Test_DownCounter_Init2);
  RUN_TEST(Test_DownCounter_Init3);
  RUN_TEST(Test_DownCounter_Count1);
  RUN_TEST(Test_DownCounter_Count2);
  RUN_TEST(Test_DownCounter_Count3);
}

#endif  // ENABLE_TESTS
