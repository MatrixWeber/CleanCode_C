// Copyright 2018 MicroConsult GmbH
#include <limits.h>
#include <stdbool.h>
#include "source/range_checker.h"

static RangeChecker *this;

static bool areInputsValid(const int lower_limit, const int upper_limit) {
    if (lower_limit >= upper_limit) {
        return false;
    }
    return true;
}

static void initDefault() {
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

static void initThis(RangeChecker *const self) {
    this = self;
    this->getUpperLimit = getUpperLimit;
    this->getLowerLimit = getLowerLimit;
    this->isInside = isInside;
}

void RangeChecker_Init(RangeChecker *const self, const int lower_limit, const int upper_limit) {
    initThis(self);
    if (areInputsValid(lower_limit, upper_limit)) {
        self->lower_limit = lower_limit;
        self->upper_limit = upper_limit;
    } else {
        initDefault();
    }
}