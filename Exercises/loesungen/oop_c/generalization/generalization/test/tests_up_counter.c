// Copyright 2018 MicroConsult GmbH
#include "test/tests.h"

#ifdef ENABLE_TESTS

#include "../../test_framework/test_functions.h"
#include "source/up_counter.h"

static void UpCountHelper(UpCounter* base, const int loops) {
  for (int i = 0; i < loops; i++) {
      UpCounter_Count(base);
  }
}

TEST(Test_UpCounter_Init1) {
  const int lower_limit = -5;
  const int upper_limit = 42;
  const int expected = lower_limit;

  UpCounter base;
  UpCounter_Init(&base, lower_limit, upper_limit);

  ASSERT(Counter_GetValue(&base.base) == expected,
         "Counter initialization failed");
}

TEST(Test_UpCounter_Init2) {
  const int lower_limit = 23;
  const int upper_limit = 42;
  const int expected = lower_limit;

  UpCounter base;
  UpCounter_Init(&base, lower_limit, upper_limit);

  ASSERT(Counter_GetValue(&base.base) == expected,
         "Counter initialization failed");
}

TEST(Test_UpCounter_Init3) {
  const int lower_limit = 23;
  const int upper_limit = 2;
  const int expected = 0;

  UpCounter base;
  UpCounter_Init(&base, lower_limit, upper_limit);

  ASSERT(Counter_GetValue(&base.base) == expected,
         "Counter initialization failed");
}

TEST(Test_UpCounter_Count1) {
  const int lower_limit = 0;
  const int upper_limit = 59;
  const int expected = 4;

  UpCounter base;
  UpCounter_Init(&base, lower_limit, upper_limit);

    UpCountHelper(&base, expected + (upper_limit + 1));

  ASSERT_INT(Counter_GetValue(&base.base), expected);
}

TEST(Test_UpCounter_Count2) {
  const int lower_limit = 0;
  const int upper_limit = 59;
  const int expected = 4;

  UpCounter base;
  UpCounter_Init(&base, lower_limit, upper_limit);

    UpCountHelper(&base, expected + (upper_limit + 1));

  ASSERT_INT(Counter_GetValue(&base.base), expected);
}

TEST(Test_UpCounter_Count3) {
  const int lower_limit = 0;
  const int upper_limit = 59;
  const int expected = 4;

  UpCounter base;
  UpCounter_Init(&base, lower_limit, upper_limit);

    UpCountHelper(&base, expected + (3 * (upper_limit + 1)));

  ASSERT_INT(Counter_GetValue(&base.base), expected);
}

TEST_SUITE(Test_UpCounter) {
  RUN_TEST(Test_UpCounter_Init1);
  RUN_TEST(Test_UpCounter_Init2);
  RUN_TEST(Test_UpCounter_Init3);
  RUN_TEST(Test_UpCounter_Count1);
  RUN_TEST(Test_UpCounter_Count2);
  RUN_TEST(Test_UpCounter_Count3);
}

#endif  // ENABLE_TESTS
