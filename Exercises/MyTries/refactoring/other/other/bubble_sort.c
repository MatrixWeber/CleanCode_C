#include <stdlib.h>
#include "bubble_sort.h"

static int CompareIntegers(const void *a, const void *b) {
    const int intA = *(const int *) a;
    const int intB = *(const int *) b;

    if (intA < intB) {
        return -1;
    } else if (intA > intB) {
        return 1;
    }
    return 0;
}

void BubbleSort(int array[], const int size) {
    qsort(array, size, sizeof(int), CompareIntegers);
}
