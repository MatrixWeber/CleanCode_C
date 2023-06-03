#include "bubble_sort.h"

static void Swap(int *first, int *second)
{
  const int temp = *first;
  *first = *second;
  *second = temp;
}

// ToDo: Convert to iteration
void BubbleSort(int array[], const int size)
{
  if (size <= 1) {
    return;
  }

  int i = 0;
  for (i = 0; i < size - 1; i++) {
    if (array[i + 1] < array[i]) {
      Swap(&array[i], &array[i + 1]);
    }
  }

  BubbleSort(array, size - 1);
}
