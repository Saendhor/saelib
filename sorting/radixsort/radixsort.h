#ifndef RADIXSORT_H
#define RADIXSORT_H

void custom_countingsort(int* to_order, int size, int exp) {
    int temp[size];
    int count[10] = {0};

    //Store number of occurences in count[]
    for (int i = 0; i < size; i++) {
        int digit = count[(to_order[i] / exp) % 10]++;
        count[digit]++;
    }

    //Cumulative counting
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    //Build output array
    for (int i = size - 1; i >= 0; i--) {
        int digit = count[(to_order[i] / exp) % 10]++;
        temp[count[(to_order[i] / exp) % 10] - 1] = to_order[i];
        count[(to_order[i] / exp) % 10]--;
    }

    //Copy values from temp to inputed array
    for (int i = 0; i < size; i++) {
        to_order[i] = temp[i];
    }
}

int radixsort(int* input, int size) {
    if (size <= 0) {
        return -1;
    }

    //find max
    int max = input[0];
    for (int i = 1; i < size; i++) {
        if (input[i] > max) max = input[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        custom_countingsort(input, size, exp);    
    }
    return 0;
}
#endif