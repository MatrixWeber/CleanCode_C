//
// Created by SW on 04.06.2023.
//

#include "year.h"

static Year *this;

static void _this(Year *const self) {
    this = self;
}

static bool isDividableBy4ButNotBy100() {
    bool isYearDividableByFour = this->year % 4 == 0;
    bool isYearNotDividableByHundred = this->year % 100 != 0;
    return isYearDividableByFour && isYearNotDividableByHundred;
}

static bool isDividableBy400() {
    bool isYearDividableByFourHundred = this->year % 400 == 0;
    if (isYearDividableByFourHundred) {
        return true;
    }
    return false;
}

bool isLeapYear() {
    if (isDividableBy400()) {
        return true;
    }
    return isDividableBy4ButNotBy100();
}

void Year_Init(Year *const self, const unsigned int year) {
    self->_this = _this;
    self->_this(self);
    self->year = year;
    self->isLeapYear = isLeapYear;
}