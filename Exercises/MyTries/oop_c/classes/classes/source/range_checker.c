// Copyright 2018 MicroConsult GmbH
#include <limits.h>
#include <stdbool.h>
#include "source/range_checker.h"

static RangeChecker* this;

static bool areInputsValid(const int lower_limit, const int upper_limit) {
    if (lower_limit >= upper_limit) {
        return false;
    }
    return true;
}

static void reinitialize() {
    this->lower_limit = 0;
    this->upper_limit = INT_MAX;
}

static int isInside(const int value) {
    if (this->lower_limit <= value && this->upper_limit >= value) {
        return 1;
    }
    return 0;
}

static int getLowerLimit() {
    return this->lower_limit;
}

static int getUpperLimit() {
    return this->upper_limit;
}

static void initializeSelf(RangeChecker *const self) {
    this = self;
    this->isInside = isInside;
    this->getLowerLimit = getLowerLimit;
    this->getUpperLimit = getUpperLimit;
}

void RangeChecker_Init(RangeChecker *const self, const int lower_limit, const int upper_limit) {
    initializeSelf(self);
    if (areInputsValid(lower_limit, upper_limit)) {
        this->lower_limit = lower_limit;
        this->upper_limit = upper_limit;
    } else {
        reinitialize();
    }
}
