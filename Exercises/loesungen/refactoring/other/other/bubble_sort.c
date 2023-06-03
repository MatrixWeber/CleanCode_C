#include "bubble_sort.h"

static void Swap(int *first, int *second)
{
  const int temp = *first;
  *first = *second;
  *second = temp;
}

void BubbleSort(int array[], const int size)
{
  if (size <= 1) {
    return;
  }

  for (int i = 0; i < size - 1; i++) {
    for (int j = 1; j < size - i; j++) {
      if (array[j] < array[j - 1]) {
        Swap(&array[j - 1], &array[j]);
      }
    }
  }
}
