//
// Created by SW on 04.06.2023.
//

#include "calendar.h"

static Calendar *this;

static const unsigned int day_info[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static void _this(Calendar *const self) {
    this = self;
}

static unsigned int calculateDaysForLeapYear(const unsigned int days) {
    if (this->year->isLeapYear()) {
        return days + 1;
    }
    return days;
}

static unsigned int calculateDays(Month *const month) {
    unsigned int days = day_info[month->month - 1];
    if (month->isFebruary()) {
        days = calculateDaysForLeapYear(days);
    }
    return days;
}

static unsigned int getDaysOfMonth(Month *const month) {
    if (month->isInvalid()) {
        return 0;
    }
    return calculateDays(month);
}

void Calendar_Init(Calendar *const self, Year *const year) {
    self->_this = _this;
    self->_this(self);
    self->year = year;
    self->getDaysOfMonth = getDaysOfMonth;
}
