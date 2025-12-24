#ifndef ARRAY_FINDMIN_H
#define ARRAY_FINDMIN_H

int array_findmin_i(int* input, int size) {
    int min = input[0]; //if it is already in order it won't perform the instruction in the if
    for (int i = 0; i < size; i++) {    // O(n)
        if (min > input[i]) {
            min = input[i];
        }
    }
    return min;
}
#endif