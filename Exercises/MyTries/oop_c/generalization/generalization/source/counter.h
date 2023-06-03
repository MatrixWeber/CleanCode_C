// Copyright 2018 MicroConsult GmbH
#ifndef SOURCE_COUNTER_H_
#define SOURCE_COUNTER_H_

#include "range_checker.h"

typedef struct _Counter {
    int value;
    RangeChecker checker;
} Counter;

void Counter_Init(Counter *const self);
void Counter_Count(Counter *const self, const int amount);
int Counter_GetValue(Counter *const self);
void Counter_Reset(Counter *const self);
void Counter_InitLimits(Counter *const self, const int lower_limit, const int upper_limit);

#endif  // SOURCE_COUNTER_H_
