#include "../include/linked_list.h"
#include <stdio.h>

void initList(LinkedList* list) {
    list->head = NULL;
}

void insertAtBeg(LinkedList* list, void* data, size_t dataSize) {
    Node* newNode = createNode(data, dataSize);
    newNode->next = list->head;
    list->head = newNode;
}

void insertAtEnd(LinkedList* list, void* data, size_t dataSize) {
    Node* newNode = createNode(data, dataSize);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteNode(LinkedList* list, void* data, int (*cmp)(void*, void*)) {
    Node *temp = list->head, *prev = NULL;
    while (temp != NULL && cmp(temp->data, data) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return; // Data not found
    if (prev == NULL) {
        list->head = temp->next;
    } else {
        prev->next = temp->next;
    }
    freeNode(temp);
}

void printList(LinkedList* list, void (*printData)(void*)) {
    Node* current = list->head;
    while (current != NULL) {
        printData(current->data);
        printf(" -> ");
        current = current->next;
    }
    printf("\n");
}

void freeList(LinkedList* list) {
    Node* current = list->head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        freeNode(current);
        current = nextNode;
    }
    list->head = NULL;
}

LinkedList* reverseList(LinkedList* list) {
    Node* prev = NULL;
    Node* current = list->head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse current node's pointer
        prev = current;        // Move pointers one position ahead
        current = next;
    }
    list->head = prev;         // Update head pointer

    return list;
}
