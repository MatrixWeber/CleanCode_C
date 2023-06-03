// Copyright 2018 MicroConsult GmbH
#include "source/range_checker.h"
#include <limits.h>

void RangeChecker_Init(RangeChecker* self, int lower_limit, int upper_limit) {
  if (lower_limit >= upper_limit) {
    self->lower_limit = 0;
    self->upper_limit = INT_MAX;
  } else {
    self->lower_limit = lower_limit;
    self->upper_limit = upper_limit;
  }
}

int RangeChecker_IsInside(RangeChecker* self, int value) {
  return (value >= self->lower_limit) && (value <= self->upper_limit);
}

int RangeChecker_GetLowerLimit(RangeChecker* self) { return self->lower_limit; }

int RangeChecker_GetUpperLimit(RangeChecker* self) { return self->upper_limit; }
