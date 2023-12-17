#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

typedef struct LinkedList {
    Node* head;
} LinkedList;

// Function to initialize a linked list
void initList(LinkedList* list);

// Functions for linked list operations

void insertAtBeg(LinkedList* list, void* data, size_t dataSize);

void insertAtEnd(LinkedList* list, void* data, size_t dataSize);

void deleteNode(LinkedList* list, void* data, int (*cmp)(void*, void*));

void printList(LinkedList* list, void (*printData)(void*));

LinkedList* reverseList(LinkedList* list);

// Function to free the entire linked list

void freeList(LinkedList* list);

#endif // LINKED_LIST_H
