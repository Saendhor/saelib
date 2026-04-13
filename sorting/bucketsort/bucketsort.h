#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include <stdlib.h>

typedef struct node {
    double key;
    struct node* next;
    
} node_t;

//support function to insert item in list (insertionsort)
node_t* insert_ordered(node_t* list, double value) {
    //create new node
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode == NULL) {
        return list;
    }
    newNode->key = value;
    newNode->next = NULL;

    if (list == NULL || list->key >= value) {
        newNode->next = list;
        return newNode;
    }

    //Search correct position
    node_t* current = list;
    while (current->next != NULL && current->next->key < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    
    return list;
}

int bucketsort(double array[], int size) {
    if (size <= 0) {
        return -1;
    }

    //Create buckets
    node_t** buckets = (node_t**)malloc(size * sizeof(node_t*));
    if (buckets == NULL) {
        return -1;
    }

    //Initialize
    for (int i = 0; i < size; i++) {
        buckets[i] = NULL;
    }

    //Insert items in buckets
    for (int i = 0; i < size; i++) {
        //bucketsort works only in the range [0, 1)
        int bucket_idx = (int)(array[i] * size); 
        // if array[i] == 1.0
        if (bucket_idx >= size) {
            bucket_idx = size - 1;
        }

        buckets[bucket_idx] = insert_ordered(buckets[bucket_idx], array[i]);
    }

    //Merge to original array
    int index = 0;
    for (int i = 0; i < size; i++) {
        node_t* current = buckets[i];
        while (current != NULL) {
            array[index++] = current->key;
            node_t* temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(buckets);
    return 0;
}

#endif