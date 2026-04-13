#ifndef CREATEHEAP_H
#define CREATEHEAP_H

#include <stdlib.h>
#include "heap_t.h"

heap_t createheap(double input[], int size) {
    heap_t new_heap;
    new_heap.total_size = size;
    new_heap.heap_size = size;
    new_heap.array = input;

    return new_heap;
}

#endif