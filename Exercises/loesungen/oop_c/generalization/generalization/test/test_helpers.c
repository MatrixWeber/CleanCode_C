// Copyright 2018 MicroConsult GmbH
#include "test/tests.h"

#ifdef ENABLE_TESTS

#include "source/counter.h"
#include "test/test_helpers.h"

void CountHelper(Counter *const counter, const int loops, const int step) {
    for (int i = 0; i < loops; i++) {
        counter->count(step);
    }
}

#endif
