#include "../include/node.h"
#include <string.h>
#include <stdio.h>

Node* createNode(void* data, size_t dataSize) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Error creating a new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = malloc(dataSize);
    if (newNode->data == NULL) {
        free(newNode);
        perror("Error allocating data for the node");
        exit(EXIT_FAILURE);
    }
    memcpy(newNode->data, data, dataSize);
    newNode->next = NULL;
    return newNode;
}

void freeNode(Node* node) {
    if (node != NULL) {
        free(node->data);
        free(node);
    }
}
