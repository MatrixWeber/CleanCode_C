#include "tests.h"
#include <stdbool.h>
#include "../../test_framework/test_functions.h"
#include "bubble_sort.h"

bool IsSorted(const int array[], const int size)
{
  for (int i = 0; i < size - 1; i++) {
    if (array[i + 1] < array[i]) {
      return false;
    }
  }

  return true;
}

TEST(TestSortRandom)
{
  int numbers[] = {5, 1, 89, 123, 34, 244, 26, 73, 4, 55};

  BubbleSort(numbers, sizeof(numbers) / sizeof(int));
  ASSERT(IsSorted(numbers, sizeof(numbers) / sizeof(int)), "Sort failed");
}

TEST(TestSortReverse)
{
  int numbers[] = {244, 123, 89, 73, 55, 34, 26, 5, 4, 1};

  BubbleSort(numbers, sizeof(numbers) / sizeof(int));
  ASSERT(IsSorted(numbers, sizeof(numbers) / sizeof(int)), "Sort failed");
}

TEST(TestSortSorted)
{
  int numbers[] = {1, 4, 5, 26, 34, 55, 73, 89, 123, 244};

  BubbleSort(numbers, sizeof(numbers) / sizeof(int));
  ASSERT(IsSorted(numbers, sizeof(numbers) / sizeof(int)), "Sort failed");
}

TEST_SUITE(TestSort)
{
  RUN_TEST(TestSortRandom);
  RUN_TEST(TestSortReverse);
  RUN_TEST(TestSortSorted);
}

void RunTests() { RUN_TEST_SUITE(TestSort); }
