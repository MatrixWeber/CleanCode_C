#include <stdbool.h>
#include <stdio.h>
#include "datehelper.h"

int GetDaysOfMonth(const int month, const int year)
{
  if (month < 1 || month > 12) {
    return 0;
  }

  int day_info[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int day_info_leap_year[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  const bool is_leap_year = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
  return is_leap_year ? day_info_leap_year[month - 1] : day_info[month - 1];
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
