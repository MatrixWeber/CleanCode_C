// Copyright 2018 MicroConsult GmbH
#include "test/tests.h"

#ifdef ENABLE_TESTS

#include "../../test_framework/test_functions.h"
#include "source/counter.h"
#include "test/test_helpers.h"

TEST(Test_CounterLimit_Init1) {
    const int lower_limit = -5;
    const int upper_limit = 42;
    const int expected = lower_limit;

    Counter counter;
    Counter_Init(&counter);
    counter.initLimits(lower_limit, upper_limit);

    ASSERT(counter.getValue() == expected,
           "Counter initialization failed");
}

TEST(Test_CounterLimit_Init2) {
    const int lower_limit = 23;
    const int upper_limit = 42;
    const int expected = lower_limit;

    Counter counter;
    Counter_Init(&counter);
    counter.initLimits(lower_limit, upper_limit);

    ASSERT(counter.getValue() == expected,
           "Counter initialization failed");
}

TEST(Test_CounterLimit_Init3) {
    const int lower_limit = 23;
    const int upper_limit = 2;
    const int expected = 0;

    Counter counter;
    Counter_Init(&counter);
    counter.initLimits(lower_limit, upper_limit);

    ASSERT(counter.getValue() == expected,
           "Counter initialization failed");
}

TEST(Test_CounterLimit_Count1) {
    const int lower_limit = 0;
    const int upper_limit = 59;
    const int expected = 4;
    const int step = 1;

    Counter counter;
    Counter_Init(&counter);
    counter.initLimits(lower_limit, upper_limit);

    CountHelper(&counter, expected + (upper_limit + 1), step);

    ASSERT_INT(counter.getValue(), expected);
}

TEST(Test_CounterLimit_Count2) {
    const int lower_limit = 0;
    const int upper_limit = 59;
    const int expected = 4;
    const int step = 1;

    Counter counter;
    Counter_Init(&counter);
    counter.initLimits(lower_limit, upper_limit);

    CountHelper(&counter, expected + (3 * (upper_limit + 1)), step);

    ASSERT_INT(counter.getValue(), expected);
}

TEST(Test_CounterLimit_Count3) {
    const int lower_limit = 0;
    const int upper_limit = 10;
    const int expected = 4;
    const int step = -1;

    Counter counter;
    Counter_Init(&counter);
    counter.initLimits(lower_limit, upper_limit);

    CountHelper(&counter, expected + (upper_limit + 1), step);

    ASSERT_INT(counter.getValue(), upper_limit - expected + 1);
}

TEST(Test_CounterLimit_Count4) {
    const int lower_limit = 0;
    const int upper_limit = 10;
    const int expected = 4;
    const int step = -1;

    Counter counter;
    Counter_Init(&counter);
    counter.initLimits(lower_limit, upper_limit);

    CountHelper(&counter, expected + (5 * (upper_limit + 1)), step);

    ASSERT_INT(counter.getValue(), upper_limit - expected + 1);
}

TEST(Test_CounterLimit_Reset1) {
    const int lower_limit = -5;
    const int upper_limit = 42;
    const int expected = lower_limit;
    const int step = 1;

    Counter counter;
    Counter_Init(&counter);
    counter.initLimits(lower_limit, upper_limit);

    CountHelper(&counter, 4, step);

    counter.reset();

    ASSERT(counter.getValue() == expected, "Counter reset failed");
}

TEST(Test_CounterLimit_Reset2) {
    const int lower_limit = -5;
    const int upper_limit = 42;
    const int expected = upper_limit;

    Counter counter;
    Counter_Init(&counter);
    counter.initLimits(lower_limit, upper_limit);

    counter.reset();

    ASSERT(counter.getValue() == expected, "Counter reset failed");
}

TEST_SUITE(Test_CounterLimit) {
    RUN_TEST(Test_CounterLimit_Init1);
    RUN_TEST(Test_CounterLimit_Init2);
    RUN_TEST(Test_CounterLimit_Init3);
    RUN_TEST(Test_CounterLimit_Count1);
    RUN_TEST(Test_CounterLimit_Count2);
    RUN_TEST(Test_CounterLimit_Count3);
    RUN_TEST(Test_CounterLimit_Count4);
    RUN_TEST(Test_CounterLimit_Reset1);
    RUN_TEST(Test_CounterLimit_Reset2);
}

#endif  // ENABLE_TESTS
