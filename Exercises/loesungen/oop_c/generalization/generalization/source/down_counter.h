// Copyright 2018 MicroConsult GmbH
#ifndef SOURCE_DOWN_COUNTER_H_
#define SOURCE_DOWN_COUNTER_H_

#include "source/counter.h"

typedef struct {
    Counter base;

    void (*count)();
} DownCounter;

void DownCounter_Init(DownCounter *self, int lower_limit, int upper_limit);


#endif  // SOURCE_DOWN_COUNTER_H_
