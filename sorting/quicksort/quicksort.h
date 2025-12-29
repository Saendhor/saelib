#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdio.h>
#include <stdlib.h>
#include "../../misc/swap.h"

int partition(double input[], int inf_index, int sup_index) {
    double value = input[sup_index];
    int index = inf_index - 1 ;
    for (int j = inf_index; j <= sup_index - 1; j++) {
        if (input[j] <= value) {
            index++;
            if (swap(&input[index], &input[j]) != 0) {
                perror("[PARTITION] Error while attempting to swap selected items");
                exit(1);
            }
        }
    }
    if (swap(&input[index + 1], &input[sup_index]) != 0) {
        perror("[PARTITION] Error while attempting to swap selected items");
        exit(1);
    }
    return index + 1;
}

int quicksort_support(double input[], int inf, int sup) {
    if (inf < sup) {
        int pivot = partition(input, inf, sup); //Splits array into 3 parts: (1) <= x ; (2) > x; (3) pivot
        if (quicksort_support(input, inf, pivot - 1) != 0) {
            perror("Error while invoking quicksort on left partitioning");
            exit(1);
        }
        if (quicksort_support(input, pivot + 1, sup) != 0) {
            perror("Error while invoking quicksort on right partitioning");
            exit(1);
        }
    }
    return 0;
}

int quicksort(double input[], int size) {
    //Support function that allows us to invoke mergesort like other sorting methods
    if (quicksort_support(input, 0, size-1) != 0) {
        printf("Error while trying to perform quicksort\n");
        return 1;
    }
    return 0;
}

#endif