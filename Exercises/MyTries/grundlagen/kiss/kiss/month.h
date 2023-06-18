//
// Created by SW on 04.06.2023.
//

#ifndef KISS_MONTH_H
#define KISS_MONTH_H

#include <stdbool.h>

typedef struct Month Month;

struct Month {
    unsigned int month;

    bool (*isInvalid)();

    bool (*isFebruary)();
};

void Month_Init(Month *const self, const unsigned int month);

#endif //KISS_MONTH_H
