// Copyright 2018 MicroConsult GmbH
#ifndef SOURCE_COUNTER_H_
#define SOURCE_COUNTER_H_

#include "range_checker.h"

typedef struct {
    int value;
    void (*count)(const int);
    int (*getValue)();
    void (*reset)();
    void (*initLimits)(const int lower_limit, const int upper_limit);
    RangeChecker checker;
} Counter;

void Counter_Init(Counter *const self);


#endif  // SOURCE_COUNTER_H_
