#ifndef BUCKETSORT_H
#define BUCKETSORT_H
#include <stdlib.h>

#include "../../misc/findmin.h"

typedef struct node {
    float* array;
    struct node* next;
    
} node_t;

node_t* new_node(int key) {
    node_t* temp = (node_t*) malloc(sizeof(node_t));
    temp->array = NULL;
    temp->next = NULL;
    return temp;
}

float bucketsort_f(float* input) {
    int size = (int) sizeof(input) / sizeof(float);
    node_t* buckets[size];

    return 0;
}
#endif