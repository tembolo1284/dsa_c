#include "../include/doubly_linked_list.h"
#include <stdio.h>
#include <string.h>

void dblListInit(DoublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

void dblListInsertAtBeg(DoublyLinkedList* list, void* data, size_t dataSize) {
    Dbl_Node* newNode = dblNodeCreate(data, dataSize);
    if (newNode == NULL) {
        return; // Failed to create a new node
    }

    newNode->next = list->head;
    newNode->prev = NULL;

    if (list->head != NULL) {
        list->head->prev = newNode;
    } else {
        list->tail = newNode; // List was empty
    }
    list->head = newNode;
}

void dblListInsertAtEnd(DoublyLinkedList* list, void* data, size_t dataSize) {
    Dbl_Node* newNode = dblNodeCreate(data, dataSize);
    if (newNode == NULL) {
        return; // Failed to create a new node
    }

    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->tail != NULL) {
        list->tail->next = newNode;
    } else {
        list->head = newNode; // List was empty
    }
    list->tail = newNode;
}

void dblListDeleteNode(DoublyLinkedList* list, void* data, int (*cmp)(void*, void*)) {
    Dbl_Node *temp = list->head;
    while (temp != NULL && cmp(temp->data, data) != 0) {
        temp = temp->next;
    }
    if (temp == NULL) return;

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        list->head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        list->tail = temp->prev;
    }

    dblNodeFree(temp);
}

void dblListPrint(DoublyLinkedList* list, void (*printData)(void*)) {
    Dbl_Node* current = list->head;
    while (current != NULL) {
        printData(current->data);
        printf(" <-> ");
        current = current->next;
    }
    printf("\n");
}

void dblListFree(DoublyLinkedList* list) {
    Dbl_Node* current = list->head;
    Dbl_Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        dblNodeFree(current);
        current = nextNode;
    }
    list->head = NULL;
    list->tail = NULL;
}

