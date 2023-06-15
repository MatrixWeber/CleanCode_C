// Copyright 2018 MicroConsult GmbH
#ifndef SOURCE_RANGE_CHECKER_H_
#define SOURCE_RANGE_CHECKER_H_

typedef struct {
    int lower_limit;
    int upper_limit;
} RangeChecker;

void RangeChecker_Init(RangeChecker *self, int lower_limit, int upper_limit);

int RangeChecker_IsInside(RangeChecker *self, int value);

int RangeChecker_GetLowerLimit(RangeChecker *self);

int RangeChecker_GetUpperLimit(RangeChecker *self);

#endif  // SOURCE_RANGE_CHECKER_H_
