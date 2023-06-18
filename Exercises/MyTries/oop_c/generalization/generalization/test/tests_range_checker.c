// Copyright 2018 MicroConsult GmbH
#include "test/tests.h"

#ifdef ENABLE_TESTS

#include <limits.h>
#include "../../test_framework/test_functions.h"
#include "source/range_checker.h"

TEST(Test_RangeChecker_Init1) {
    const int lower_limit = 0;
    const int upper_limit = 5;

    RangeChecker checker;
    RangeChecker_Init(&checker, lower_limit, upper_limit);

    ASSERT(lower_limit == checker.getLowerLimit(),
           "BoundaryChecker lower limit was not correct initialized");
    ASSERT(upper_limit == checker.getUpperLimit(),
           "BoundaryChecker upper limit was not correct initialized");
}

TEST(Test_RangeChecker_Init2) {
    const int lower_limit = -10;
    const int upper_limit = 5;

    RangeChecker checker;
    RangeChecker_Init(&checker, lower_limit, upper_limit);

    ASSERT(lower_limit == checker.getLowerLimit(),
           "BoundaryChecker lower limit was not correct initialized");
    ASSERT(upper_limit == checker.getUpperLimit(),
           "BoundaryChecker upper limit was not correct initialized");
}

TEST(Test_RangeChecker_Init3) {
    const int lower_limit = 23;
    const int upper_limit = -42;

    RangeChecker checker;
    RangeChecker_Init(&checker, lower_limit, upper_limit);

    // checker should use the defaults
    ASSERT(checker.getLowerLimit() == 0,
           "BoundaryChecker lower limit was not correct initialized");
    ASSERT(checker.getUpperLimit() == INT_MAX,
           "BoundaryChecker upper limit was not correct initialized");
}

TEST(Test_RangeChecker_Inside1) {
    const int lower_limit = 0;
    const int upper_limit = 5;
    const int test_value = 3;

    RangeChecker checker;
    RangeChecker_Init(&checker, lower_limit, upper_limit);

    ASSERT(checker.isInside(test_value),
           "Test value is inside the boundary, result should be true");
}

TEST(Test_RangeChecker_Inside2) {
    const int lower_limit = 0;
    const int upper_limit = 5;
    const int test_value = 0;

    RangeChecker checker;
    RangeChecker_Init(&checker, lower_limit, upper_limit);

    ASSERT(checker.isInside(test_value),
           "Test value is inside the boundary, result should be true");
}

TEST(Test_RangeChecker_Inside3) {
    const int lower_limit = 0;
    const int upper_limit = 5;
    const int test_value = 5;

    RangeChecker checker;
    RangeChecker_Init(&checker, lower_limit, upper_limit);

    ASSERT(checker.isInside(test_value),
           "Test value is inside the boundary, result should be true");
}

TEST(Test_RangeChecker_Outside1) {
    const int lower_limit = -7;
    const int upper_limit = 5;
    const int test_value = 12;

    RangeChecker checker;
    RangeChecker_Init(&checker, lower_limit, upper_limit);

    ASSERT(!checker.isInside(test_value),
           "Test value is outside the boundary, result should be false");
}

TEST(Test_RangeChecker_Outside2) {
    const int lower_limit = -7;
    const int upper_limit = 5;
    const int test_value = -8;

    RangeChecker checker;
    RangeChecker_Init(&checker, lower_limit, upper_limit);

    ASSERT(!checker.isInside(test_value),
           "Test value is outside the boundary, result should be false");
}

TEST(Test_RangeChecker_Outside3) {
    const int lower_limit = -7;
    const int upper_limit = 5;
    const int test_value = 6;

    RangeChecker checker;
    RangeChecker_Init(&checker, lower_limit, upper_limit);

    ASSERT(!checker.isInside(test_value),
           "Test value is outside the boundary, result should be false");
}

TEST_SUITE(Test_RangeChecker) {
    RUN_TEST(Test_RangeChecker_Init1);
    RUN_TEST(Test_RangeChecker_Init2);
    RUN_TEST(Test_RangeChecker_Init3);
    RUN_TEST(Test_RangeChecker_Inside1);
    RUN_TEST(Test_RangeChecker_Inside2);
    RUN_TEST(Test_RangeChecker_Inside3);
    RUN_TEST(Test_RangeChecker_Outside1);
    RUN_TEST(Test_RangeChecker_Outside2);
    RUN_TEST(Test_RangeChecker_Outside3);
}

#endif  // ENABLE_TESTS
