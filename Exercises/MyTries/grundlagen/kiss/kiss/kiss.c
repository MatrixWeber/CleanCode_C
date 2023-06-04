#include <stdio.h>
#include "datehelper.h"
#include "calendar.h"
#include "month.h"

int main() {
    DateHelper test_data[] = {{1,  2013, 31},
                              {2,  2013, 28},
                              {3,  2013, 31},
                              {4,  2013, 30},
                              {5,  2013, 31},
                              {6,  2013, 30},
                              {2,  1940, 29},
                              {7,  2013, 31},
                              {8,  2013, 31},
                              {2,  2000, 29},
                              {9,  2013, 30},
                              {10, 2013, 31},
                              {2,  1700, 28},
                              {11, 2013, 30},
                              {12, 2013, 31},
                              {13, 2013, 0}};

    const int number_of_data = sizeof(test_data) / sizeof(DateHelper);
    for (int i = 0; i < number_of_data; ++i) {
        Year year;
        Year_Init(&year, test_data[i].year);
        Month month;
        Month_Init(&month, test_data[i].month);
        Calendar calendar;
        Calendar_Init(&calendar, &year);
        unsigned int number_of_days_of_month = calendar.getDaysOfMonth(&month);
        if (number_of_days_of_month != test_data[i].days) {
            printf("ERROR: Year: %d, Month: %d, Days %d (Expected %d)\n",
                   test_data[i].year, test_data[i].month, number_of_days_of_month, test_data[i].days);
        } else {
            printf("Year: %d, Month: %d, Days %d\n", test_data[i].year,
                   test_data[i].month, number_of_days_of_month);
        }
    }

    return 0;
}
