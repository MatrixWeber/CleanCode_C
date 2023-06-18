//
// Created by SW on 04.06.2023.
//

#include "month.h"

static Month *this;

static bool isInvalid() {
    return (this->month < 1 || this->month > 12);
}

static bool isFebruary() {
    return this->month == 2;
}

void Month_Init(Month *const self, const unsigned int month) {
    this = self;
    self->month = month;
    self->isFebruary = isFebruary;
    self->isInvalid = isInvalid;
}
