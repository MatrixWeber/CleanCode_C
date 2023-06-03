// Copyright 2018 MicroConsult GmbH
#ifndef SOURCE_DOWN_COUNTER_H_
#define SOURCE_DOWN_COUNTER_H_

#include "source/counter.h"

typedef struct _DownCounter {
  Counter base;
} DownCounter;

void DownCounter_Init(DownCounter* self, int lower_limit, int upper_limit);

void DownCounter_Count(DownCounter* self);

#endif  // SOURCE_DOWN_COUNTER_H_
