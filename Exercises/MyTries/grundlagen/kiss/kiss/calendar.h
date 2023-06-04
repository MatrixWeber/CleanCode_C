//
// Created by SW on 04.06.2023.
//

#ifndef KISS_CALENDAR_H
#define KISS_CALENDAR_H

#include "year.h"
#include "month.h"

typedef struct Calendar Calendar;

struct Calendar {
    void (*_this)(Calendar *const);

    Year *year;

    unsigned int (*getDaysOfMonth)(Month *const);

    unsigned int (*calculateDaysForLeapYear)(const unsigned int);
};

void Calendar_Init(Calendar *const self, Year *const year);

#endif //KISS_CALENDAR_H