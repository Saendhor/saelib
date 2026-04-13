#ifndef HEAPSORT_H
#define HEAPSORT_H


#include "heap/createheap.h"
#include "heap/maxheap_build.h"

int heapsort(double input[], int size) {
    heap_t heap = createheap(input, size);
    maxheap_build(heap);
    for (int i = size - 1; i > 0 ; i--) {
        swap(&input[0], &input[i]);
        heap.heap_size--;
        maxheap_heapify(heap, 0);
    }
    return 0;
}

#endif