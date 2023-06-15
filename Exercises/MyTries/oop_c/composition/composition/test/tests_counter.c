// Copyright 2018 MicroConsult GmbH
#include "test/tests.h"

#ifdef ENABLE_TESTS

#include "../../test_framework/test_functions.h"
#include "source/counter.h"
#include "test/test_helpers.h"

TEST(Test_Counter_Init) {
    const int expected = 0;

    Counter counter;
    Counter_Init(&counter);

    ASSERT(counter.getValue() == expected, "Counter initialization failed");
}

TEST(Test_Counter_Count) {
    const int expected = 4;
    const int step = 1;

    Counter counter;
    Counter_Init(&counter);

    CountHelper(&counter, expected, step);

    ASSERT_INT(counter.getValue(), expected);
}

TEST(Test_Counter_Reset) {
    const int expected = 0;
    const int step = 1;

    Counter counter;
    Counter_Init(&counter);

    CountHelper(&counter, 42, step);

    counter.reset();

    ASSERT(counter.getValue() == expected, "Counter reset failed");
}

TEST(Test_Multiple_Counter_Count) {
    const int expected1 = 42;
    const int expected2 = 15;
    const int step1 = 1;
    const int step2 = 3;

    Counter counter1;
    Counter_Init(&counter1);
    CountHelper(&counter1, expected1, step1);
    ASSERT_INT(counter1.getValue(), expected1);

    Counter counter2;
    Counter_Init(&counter2);
    CountHelper(&counter2, expected2 / step2, step2);
    ASSERT_INT(counter2.getValue(), expected2);
}

TEST_SUITE(Test_Counter) {
    RUN_TEST(Test_Counter_Init);
    RUN_TEST(Test_Counter_Count);
    RUN_TEST(Test_Counter_Reset);
    RUN_TEST(Test_Multiple_Counter_Count);
}

#endif  // ENABLE_TESTS
