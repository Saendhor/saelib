#ifndef ARRAY_FINDMAX_H
#define ARRAY_FINDMAX_H

double array_findmax(double input[], int size) {
    int max = input[size - 1]; //if it is already in order it won't perform the instruction in the if
    for (int i = 0; i < size; i++) {
        if (max < input[i]) {
            max = input[i];
        }
    }
    return max;
}


int array_findmax_i(int input[], int size) {
    int max = input[size - 1]; //if it is already in order it won't perform the instruction in the if
    for (int i = 0; i < size; i++) {
        if (max < input[i]) {
            max = input[i];
        }
    }
    return max;
}
#endif