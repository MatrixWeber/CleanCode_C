// Copyright 2018 MicroConsult GmbH
#ifndef SOURCE_COUNTER_H_
#define SOURCE_COUNTER_H_

#include "source/range_checker.h"

typedef struct _Counter {
  int value;
  RangeChecker checker;
} Counter;

void Counter_Init(Counter* self);
void Counter_InitLimits(Counter* self, int lower_limit, int upper_limit);

void Counter_Count(Counter* self, int amount);
int Counter_GetValue(const Counter* self);
void Counter_Reset(Counter* self);

#endif  // SOURCE_COUNTER_H_
