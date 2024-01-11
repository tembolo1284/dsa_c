#include "../include/dbl_node.h"
#include <string.h>

Dbl_Node* dblNodeCreate(void* data, size_t dataSize) {
    Dbl_Node* newNode = (Dbl_Node*)malloc(sizeof(Dbl_Node));
    if (newNode == NULL) {
        return NULL; // Allocation failed
    }

    newNode->data = malloc(dataSize);
    if (newNode->data == NULL) {
        free(newNode); // Allocation for data failed
        return NULL;
    }
    memcpy(newNode->data, data, dataSize);

    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void dblNodeFree(Dbl_Node* node) {
    if (node != NULL) {
        free(node->data);
        free(node);
    }
}

