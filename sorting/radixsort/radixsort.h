#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <stddef.h>
#include <stdlib.h>

// * was: void custom_countingsort + VLA + count[...]++ as index
static void custom_countingsort(int* a, int size, int exp) {
    int* out = (int*)malloc(size * sizeof(int)); // * was: int temp[size]
    if (out == NULL) return; // caller checks, or return int
    int count[10] = {0};

    for (int i = 0; i < size; i++) // * was: count[digit]++
        count[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) { // * single eval, no ++/--
        int d = (a[i] / exp) % 10;
        out[--count[d]] = a[i];
    }
    for (int i = 0; i < size; i++) a[i] = out[i];
    free(out);
}

int radixsort(int* input, int size) {
    if (input == NULL || size <= 0) return -1; // * was: no NULL
    // * was: max-only, negatives -> negative %10 OOB
    // simplest: reject, or split neg/pos
    for (int i = 0; i < size; i++)
        if (input[i] < 0) return -1; // document non-negative only

    int max = input[0];
    for (int i = 1; i < size; i++)
        if (input[i] > max) max = input[i];

    // * was: exp*=10 can overflow signed
    for (long exp = 1; max / exp > 0; ) {
        custom_countingsort(input, size, (int)exp);
        if (exp > max / 10) break;
        exp *= 10;
    }
    return 0;
}

#endif