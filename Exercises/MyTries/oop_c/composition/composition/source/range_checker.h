// Copyright 2018 MicroConsult GmbH
#ifndef SOURCE_RANGE_CHECKER_H_
#define SOURCE_RANGE_CHECKER_H_

typedef struct {
    int lower_limit;
    int upper_limit;
    int (*isInside)(const int);
    int (*getLowerLimit)();
    int (*getUpperLimit)();
} RangeChecker;

void RangeChecker_Init(RangeChecker *const self, const int lower_limit, const int upper_limit);

#endif  // SOURCE_RANGE_CHECKER_H_
