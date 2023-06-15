// Copyright 2018 MicroConsult GmbH
#include "source/counter.h"

static Counter *this;

static void count(const int amount) { this->value += amount; }

static int getValue() { return this->value; }

static void reset() { this->value = 0; }

void Counter_Init(Counter *const self) {
    this = self;
    this->reset = reset;
    this->count = count;
    this->getValue = getValue;
    this->reset();
}
