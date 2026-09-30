#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <stddef.h>
#include <stdlib.h>

int countingsort(int* input, int size) {
    if (input == NULL || size <= 0) {
        return -1;
    }

    //find min and max
    int min = input[0], max = input[0];
    for (int i = 1; i < size; i++) {
        if (input[i] < min) min = input[i];
        if (input[i] > max) max = input[i];
    }

    size_t k = (size_t)max - (size_t)min + 1; // * range, not max+1
    if (k > (size_t)size * 32 && k > 1024) { // * guard huge alloc
        return -1; // fallback to mergesort/quicksort
    }

    //create C array and initialize it to 0
    int* num_values = (int*)calloc(k, sizeof(int));
    if (num_values == NULL) return -1; //check memory

    int* ordered_input = (int*)malloc(size * sizeof(int));
    if (ordered_input == NULL) {
        free(num_values);
        return -1;
    }

    //increase the amount of occurences of the A[j] value in C
    for (int j = 0; j < size; j++) { // * offset by min
        num_values[input[j] - min]++;
    }

    //define the cumulative amount in the array C
    for (size_t i = 1; i < k; i++) {
        num_values[i] += num_values[i - 1];
    }

    //creating the array of the ordered input (stable)
    for (int j = size - 1; j >= 0; j--) { // * offset, pre-decrement
        ordered_input[--num_values[input[j] - min]] = input[j];
    }

    //Copying the ordered values inside the inputed array
    for (int i = 0; i < size; i++) {
        input[i] = ordered_input[i];
    }

    free(ordered_input);
    free(num_values);
    return 0;
}

#endif