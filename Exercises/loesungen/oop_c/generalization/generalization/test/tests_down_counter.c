// Copyright 2018 MicroConsult GmbH
#include "test/tests.h"

#ifdef ENABLE_TESTS

#include <limits.h>
#include "../../test_framework/test_functions.h"
#include "source/down_counter.h"

static void DownCountHelper(DownCounter *counter, const int loops) {
    for (int i = 0; i < loops; i++) {
        counter->count();
    }
}

TEST(Test_DownCounter_Init1) {
    const int lower_limit = -5;
    const int upper_limit = 42;
    const int expected = upper_limit;

    DownCounter counter;
    DownCounter_Init(&counter, lower_limit, upper_limit);

    ASSERT(counter.base.getValue() == expected,
           "Counter initialization failed");
}

TEST(Test_DownCounter_Init2) {
    const int lower_limit = 23;
    const int upper_limit = 42;
    const int expected = upper_limit;

    DownCounter counter;
    DownCounter_Init(&counter, lower_limit, upper_limit);

    ASSERT(counter.base.getValue() == expected,
           "Counter initialization failed");
}

TEST(Test_DownCounter_Init3) {
    const int lower_limit = 23;
    const int upper_limit = 2;
    const int expected = INT_MAX;

    DownCounter counter;
    DownCounter_Init(&counter, lower_limit, upper_limit);

    ASSERT(counter.base.getValue() == expected,
           "Counter initialization failed");
}

TEST(Test_DownCounter_Count1) {
    const int lower_limit = 0;
    const int upper_limit = 59;
    const int expected = 4;

    DownCounter counter;
    DownCounter_Init(&counter, lower_limit, upper_limit);

    DownCountHelper(&counter, expected);

    ASSERT_INT(counter.base.getValue(), upper_limit - expected);
}

TEST(Test_DownCounter_Count2) {
    const int lower_limit = 0;
    const int upper_limit = 59;
    const int expected = 4;

    DownCounter counter;
    DownCounter_Init(&counter, lower_limit, upper_limit);

    DownCountHelper(&counter, expected + (upper_limit + 1));

    ASSERT_INT(counter.base.getValue(), upper_limit - expected);
}

TEST(Test_DownCounter_Count3) {
    const int lower_limit = 0;
    const int upper_limit = 59;
    const int expected = 4;

    DownCounter counter;
    DownCounter_Init(&counter, lower_limit, upper_limit);

    DownCountHelper(&counter, expected + (3 * (upper_limit + 1)));

    ASSERT_INT(counter.base.getValue(), upper_limit - expected);
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
