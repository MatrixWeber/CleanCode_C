// Copyright 2018 MicroConsult GmbH
#include <limits.h>
#include "source/counter.h"

void Counter_Init(Counter *const self) {
    Counter_InitLimits(self, 0, INT_MAX);
}

void Counter_InitLimits(Counter *const self, const int lower_limit, const int upper_limit) {
    RangeChecker_Init(&self->checker, lower_limit, upper_limit);
    self->value = RangeChecker_GetLowerLimit(&self->checker);
}

void Counter_Count(Counter *const self, const int amount) {
    self->value += amount;
    if (!RangeChecker_IsInside(&self->checker, self->value)) {
        Counter_Reset(self);
    }
}

int Counter_GetValue(Counter *const self) { return self->value; }

void Counter_Reset(Counter *const self) {
    if (self->value <= RangeChecker_GetLowerLimit(&self->checker)) {
        self->value = RangeChecker_GetUpperLimit(&self->checker);;
    } else {
        self->value = RangeChecker_GetLowerLimit(&self->checker);
    }
}