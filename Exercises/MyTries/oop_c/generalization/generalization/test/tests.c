// Copyright 2018 MicroConsult GmbH
#include "test/tests.h"
#include "../../test_framework/test_functions.h"

#ifdef ENABLE_TESTS

TEST_SUITE(Test_Counter);

TEST_SUITE(Test_RangeChecker);

TEST_SUITE(Test_CounterLimit);

TEST_SUITE(Test_UpCounter);

TEST_SUITE(Test_DownCounter);

void RunTests() {
    RUN_TEST_SUITE(Test_Counter);
    RUN_TEST_SUITE(Test_RangeChecker);
    RUN_TEST_SUITE(Test_CounterLimit);
    RUN_TEST_SUITE(Test_UpCounter);
    RUN_TEST_SUITE(Test_DownCounter);
}

#else
void RunTests() {}
#endif  // ENABLE_TESTS
