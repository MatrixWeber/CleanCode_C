// Copyright 2018 MicroConsult GmbH
#include <limits.h>
#include "source/counter.h"

static Counter *this;

static void initLimits(const int lower_limit, const int upper_limit) {
    RangeChecker_Init(&this->checker, lower_limit, upper_limit);
    this->value = this->checker.getLowerLimit();
}

static void count(const int amount) {
    this->value += amount;
    if (!this->checker.isInside(this->value)) {
        this->reset();
    }
}

static int getValue() { return this->value; }

static void reset() {
    if (this->value <= this->checker.getLowerLimit()) {
        this->value = this->checker.getUpperLimit();;
    } else {
        this->value = this->checker.getLowerLimit();
    }
}

void Counter_Init(Counter *const self) {
    this = self;
    this->count = count;
    this->getValue = getValue;
    this->reset = reset;
    this->initLimits = initLimits;
    this->initLimits(0, INT_MAX);
}
