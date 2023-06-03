// Copyright 2018 MicroConsult GmbH
#include "test/tests.h"

#ifdef ENABLE_TESTS

#include "test/test_helpers.h"
#include "counter.h"

void CountHelper(Counter* base, const int loops, const int step) {
  for (int i = 0; i < loops; i++) {
    Counter_Count(base, step);
  }
}

#endif
