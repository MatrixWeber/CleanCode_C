// Copyright 2018 MicroConsult GmbH
#ifndef SOURCE_UP_COUNTER_H_
#define SOURCE_UP_COUNTER_H_

#include "source/counter.h"

typedef struct {
    Counter base;

    void (*count)();

} UpCounter;

void UpCounter_Init(UpCounter *const self, const int lower_limit, const int upper_limit);

#endif  // SOURCE_UP_COUNTER_H_
