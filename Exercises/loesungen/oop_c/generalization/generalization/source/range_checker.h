// Copyright 2018 MicroConsult GmbH
#ifndef SOURCE_RANGE_CHECKER_H_
#define SOURCE_RANGE_CHECKER_H_

typedef struct _RangeChecker {
    int lower_limit;
    int upper_limit;
} RangeChecker;

void RangeChecker_Init(RangeChecker *const self, const int lower_limit, const int upper_limit);

int RangeChecker_IsInside(RangeChecker *const self, const int value);
int RangeChecker_GetLowerLimit(RangeChecker *const self);
int RangeChecker_GetUpperLimit(RangeChecker *const self);

#endif  // SOURCE_RANGE_CHECKER_H_
