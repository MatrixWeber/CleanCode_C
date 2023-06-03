// Copyright 2018 MicroConsult GmbH
#include <limits.h>
#include <stdbool.h>
#include "source/range_checker.h"

static bool AreInputsValid(RangeChecker *const self, const int lower_limit, const int upper_limit) {
    if (lower_limit >= upper_limit) {
        return false;
    }
    return true;
}

static void Reinitialize(RangeChecker *const self) {
    self->lower_limit = 0;
    self->upper_limit = INT_MAX;
}

void RangeChecker_Init(RangeChecker *const self, const int lower_limit, const int upper_limit) {
    if (AreInputsValid(self, lower_limit, upper_limit)) {
        self->lower_limit = lower_limit;
        self->upper_limit = upper_limit;
    } else {
        Reinitialize(self);
    }
}

int RangeChecker_IsInside(RangeChecker *const self, const int value) {
    if (self->lower_limit <= value && self->upper_limit >= value) {
        return 1;
    }
    return 0;
}

int RangeChecker_GetLowerLimit(RangeChecker *const self) {
    return self->lower_limit;
}

int RangeChecker_GetUpperLimit(RangeChecker *const self) {
    return self->upper_limit;
}