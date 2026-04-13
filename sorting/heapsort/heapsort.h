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

/*
int heapsort(double input[], int size) {
    heap_t heap = createheap_i(input, size);
    heap.heap_size = size; // Assicurati che la dimensione sia corretta
    maxheap_build(heap);
    
    // Si parte dall'ultimo elemento (size - 1) fino al secondo (1)
    for (int i = size - 1; i > 0; i--) {
        swap(&input[0], &input[i]);
        heap.heap_size--; // Riduciamo l'heap virtuale
        maxheap_heapify(heap, 0); // Ripristiniamo sempre dalla radice (0)
    }
    return 0;
}
    */