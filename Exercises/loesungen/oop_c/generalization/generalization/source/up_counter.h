// Copyright 2018 MicroConsult GmbH
#ifndef SOURCE_UP_COUNTER_H_
#define SOURCE_UP_COUNTER_H_

#include "source/counter.h"

typedef struct _UpCounter {
    Counter base;
} UpCounter;

void UpCounter_Init(UpCounter *const self, const int lower_limit, const int upper_limit);

void UpCounter_Count(UpCounter *const self);

#endif  // SOURCE_UP_COUNTER_H_
