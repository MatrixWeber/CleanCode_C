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

static void _this(Month *const self) {
    this = self;
}

void Month_Init(Month *const self, const unsigned int month) {
    self->_this = _this;
    self->_this(self);
    self->month = month;
    self->isFebruary = isFebruary;
    self->isInvalid = isInvalid;
}
