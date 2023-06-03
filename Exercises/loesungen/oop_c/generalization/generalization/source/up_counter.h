// Copyright 2018 MicroConsult GmbH
#ifndef SOURCE_UP_COUNTER_H_
#define SOURCE_UP_COUNTER_H_

#include "source/counter.h"

typedef struct _UpCounter {
  Counter base;
} UpCounter;

void UpCounter_Init(UpCounter* self, int lower_limit, int upper_limit);

void UpCounter_Count(UpCounter* self);

#endif  // SOURCE_UP_COUNTER_H_
