#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <stdlib.h>
#include <string.h>
#include "../../misc/array_findmax.h"

int countingsort(int* input, int size) {
    if (size <= 0) {
        return -1;
    }

    int max = array_findmax_i(input, size);

    //create C array and initialize it to 0
    int* num_values = (int*)calloc(max + 1, sizeof(int));
    if (num_values == NULL) return -1; //check memory

    //increase the amount of occurences of the A[j] value in C
    for (int j = 0; j < size; j++) {
        num_values[input[j]]++;
    }

    //define the cumulative amount in the array C
    for (int i = 1; i < max; i++) {
        num_values[i] += num_values[i - 1];
    }

    //creating the array of the ordered input (stable)
    int ordered_input[size];
    for (int j = size; j > 0; j--) {
        ordered_input[num_values[input[j]] - 1] = input[j];
        num_values[input[j]]--;
    }

    //Copying the ordered values inside the inputed array
    for (int i = 0; i < size; i++) {
        input[i] = ordered_input[i];
    }

    free(num_values);
    return 0;
}

#endif