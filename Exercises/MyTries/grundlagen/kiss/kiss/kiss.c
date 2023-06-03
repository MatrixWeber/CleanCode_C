#include <stdio.h>
#include "datehelper.h"

// ToDo: Funktion GetDaysOfMonth vereinfachen
int GetDaysOfMonth(const int month, const int year)
{
  int i = month;

  if (i > 7) {
    i = i - 7;
  }

  i = 30 + i % 2;

  if (month == 2) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
      i = i - 1;
    }
    else {
      i = i - 2;
    }
  }

  if (month < 1 || month > 12) {
    return 0;
  }

  return i;
}

int main()
{
  DateHelper test_data[] = {{1, 2013, 31}, {2, 2013, 28},  {3, 2013, 31},
                            {4, 2013, 30}, {5, 2013, 31},  {6, 2013, 30},
                            {2, 1940, 29}, {7, 2013, 31},  {8, 2013, 31},
                            {2, 2000, 29}, {9, 2013, 30},  {10, 2013, 31},
                            {2, 1700, 28}, {11, 2013, 30}, {12, 2013, 31}};

  const int number_of_data = sizeof(test_data) / sizeof(DateHelper);
  for (int i = 0; i < number_of_data; ++i) {
    const int days = GetDaysOfMonth(test_data[i].month, test_data[i].year);

    if (days != test_data[i].days) {
      printf("ERROR: Year: %d, Month: %d, Days %d (Expected %d)\n",
             test_data[i].year, test_data[i].month, days, test_data[i].days);
    }
    else {
      printf("Year: %d, Month: %d, Days %d\n", test_data[i].year,
             test_data[i].month, days);
    }
  }

  return 0;
}
