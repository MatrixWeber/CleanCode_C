// Copyright 2018 MicroConsult GmbH
#include "source/counter.h"
#include <limits.h>

void Counter_Init(Counter *self) { Counter_InitLimits(self, 0, INT_MAX); }

void Counter_InitLimits(Counter *self, int lower_limit, int upper_limit) {
    RangeChecker_Init(&self->checker, lower_limit, upper_limit);
    self->value = RangeChecker_GetLowerLimit(&self->checker);
}

void Counter_Count(Counter *self, int amount) {
    self->value += amount;

    if (!RangeChecker_IsInside(&self->checker, self->value)) {
        Counter_Reset(self);
    }
}

int Counter_GetValue(const Counter *self) { return self->value; }

void Counter_Reset(Counter *self) {
    if (self->value <= RangeChecker_GetLowerLimit(&self->checker)) {
        self->value = RangeChecker_GetUpperLimit(&self->checker);
    } else {
        self->value = RangeChecker_GetLowerLimit(&self->checker);
    }
}
