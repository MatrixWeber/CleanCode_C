//
// Created by SW on 04.06.2023.
//

#ifndef KISS_YEAR_H
#define KISS_YEAR_H

#include <stdbool.h>

typedef struct Year Year;

struct Year {
    unsigned int year;

    bool (*isLeapYear)();
};

void Year_Init(Year *const self, const unsigned int year);

#endif //KISS_YEAR_H
