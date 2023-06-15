// Copyright 2018 MicroConsult GmbH
#include "test/tests.h"
#include "../../test_framework/test_functions.h"

#ifdef ENABLE_TESTS

TEST_SUITE(Test_Counter);

TEST_SUITE(Test_RangeChecker);

TEST_SUITE(Test_CounterLimit);


void RunTests() {
    RUN_TEST_SUITE(Test_Counter);
    RUN_TEST_SUITE(Test_RangeChecker);
    RUN_TEST_SUITE(Test_CounterLimit);
}

#else
void RunTests() {}
#endif  // ENABLE_TESTS
