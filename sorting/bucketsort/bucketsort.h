#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include <math.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct node {
    double key;
    struct node* next;
} node_t;

//support function to insert item in list (insertionsort)
static int insert_ordered(node_t** head, double value) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode == NULL) return -1;
    newNode->key = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->key >= value) {
        newNode->next = *head;
        *head = newNode;
        return 0;
    }
    node_t* current = *head;
    while (current->next != NULL && current->next->key < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return 0;
}

// * new: cleanup helper for error paths
static void free_buckets(node_t** buckets, int size) {
    if (buckets == NULL) return;
    for (int i = 0; i < size; i++) {
        node_t* c = buckets[i];
        while (c != NULL) {
            node_t* t = c;
            c = c->next;
            free(t);
        }
    }
    free(buckets);
}

int bucketsort(double array[], int size) {
    if (array == NULL || size <= 0) {
        return -1;
    }

    // generalize to any finite range via min/max
    double min = array[0], max = array[0];
    for (int i = 1; i < size; i++) {
        //Throw error
        if (!isfinite(array[i])){
            return -1;
        }
        //assign min and max
        if (array[i] < min) min = array[i];
        if (array[i] > max) max = array[i];
    }
    if (!isfinite(array[0])) return -1;
    if (min == max) return 0; // all equal
    double range = max - min;

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
        int idx = (int)((array[i] - min) / range * size);
        if (idx < 0) idx = 0; // float rounding guard
        if (idx >= size) idx = size - 1; // max edge, old 1.0 case
        if (insert_ordered(&buckets[idx], array[i]) != 0) {
            free_buckets(buckets, size); // * was: leak + data loss
            return -1;
        }
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