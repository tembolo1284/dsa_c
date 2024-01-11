#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "dbl_node.h"

typedef struct DoublyLinkedList {
    Dbl_Node* head;
    Dbl_Node* tail;
} DoublyLinkedList;

void dblListInit(DoublyLinkedList* list);
void dblListInsertAtBeg(DoublyLinkedList* list, void* data, size_t dataSize);
void dblListInsertAtEnd(DoublyLinkedList* list, void* data, size_t dataSize);
void dblListDeleteNode(DoublyLinkedList* list, void* data, int (*cmp)(void*, void*));
void dblListPrint(DoublyLinkedList* list, void (*printData)(void*));
void dblListFree(DoublyLinkedList* list);

#endif // DOUBLY_LINKED_LIST_H

