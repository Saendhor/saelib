#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct list {
    node_t *head;
    int num_elements;
    
} list_t;

static node_t *new_node(int key) {
    node_t *temp = (node_t*) malloc(sizeof(node_t));
    if(temp == NULL) {
        fprintf(stderr, "[LIST] Error while allocating memory for node\n");
        exit(EXIT_FAILURE);
    }
    temp->key = key;
    temp->next = NULL;
    
    return temp;
}

static list_t *new_list() {
    list_t *temp = (list_t*) malloc(sizeof(list_t));
    if(temp == NULL) {
        fprintf(stderr, "[LIST] Error while allocating memory for list\n");
        exit(EXIT_FAILURE);
    }
    temp->head = NULL;
    temp->num_elements = 0;

    return temp;
}

#endif