#include <criterion/criterion.h>
#include <criterion/logging.h>
#include "../include/doubly_linked_list.h"
#include "../include/utils.h" 


// Test case for doubly linked list initialization
Test(doubly_linked_list, initialization) {
    DoublyLinkedList list;
    dblListInit(&list);
    cr_assert_null(list.head, "DoublyLinkedList head should be NULL after initialization");
    cr_assert_null(list.tail, "DoublyLinkedList tail should be NULL after initialization");
}

// Test case for inserting at the beginning with int type
Test(doubly_linked_list, insertAtBegInt) {
    DoublyLinkedList list;
    dblListInit(&list);
    int data = 10;
    dblListInsertAtBeg(&list, &data, sizeof(data));
    cr_assert_not_null(list.head, "Head should not be NULL after insertion");
    cr_assert_eq(*(int*)list.head->data, data, "Data at the head is not correct after insertion");
    dblListFree(&list);
}

// Test case for inserting at the beginning with double type
Test(doubly_linked_list, insertAtBegDbl) {
    DoublyLinkedList list;
    dblListInit(&list);
    double data = 10.125;
    dblListInsertAtBeg(&list, &data, sizeof(data));
    cr_assert_not_null(list.head, "Head should not be NULL after insertion");
    cr_assert_eq(*(double*)list.head->data, data, "Data at the head is not correct after insertion");
    dblListFree(&list);
}

// Test case for inserting at the beginning with char type
Test(doubly_linked_list, insertAtBegChar){
    DoublyLinkedList list;
    dblListInit(&list);
    char data = 'a';
    dblListInsertAtBeg(&list, &data, sizeof(data));
    cr_assert_not_null(list.head, "Head should not be NULL after insertion");
    cr_assert_eq(*(char*)list.head->data, data, "Data at the head is not correct after insertion");
    dblListFree(&list);
}

// Test case for inserting at the end
Test(doubly_linked_list, insertAtEnd) {
    DoublyLinkedList list;
    dblListInit(&list);
    int data = 20;
    dblListInsertAtEnd(&list, &data, sizeof(data));
    cr_assert_not_null(list.tail, "Tail should not be NULL after insertion");
    cr_assert_eq(*(int*)list.tail->data, data, "Data at the tail is not correct after insertion");
    dblListFree(&list);
}

// Test case for deleting a node
Test(doubly_linked_list, deleteNode) {
    DoublyLinkedList list;
    dblListInit(&list);
    int data = 30;
    dblListInsertAtEnd(&list, &data, sizeof(data));
    dblListDeleteNode(&list, &data, compareInts);
    cr_assert_null(list.head, "Head should be NULL after deletion");
    cr_assert_null(list.tail, "Tail should be NULL after deletion");
    dblListFree(&list);
}

// Test case for list with multiple nodes
Test(doubly_linked_list, multipleNodes) {
    DoublyLinkedList list;
    dblListInit(&list);
    int data1 = 40, data2 = 50;
    dblListInsertAtEnd(&list, &data1, sizeof(data1));
    dblListInsertAtEnd(&list, &data2, sizeof(data2));
    cr_assert_eq(*(int*)list.head->data, data1, "First node data is not correct");
    cr_assert_eq(*(int*)list.tail->data, data2, "Last node data is not correct");
    dblListFree(&list);
}

// Test for correct prev linkage
Test(doubly_linked_list, prevLinkage) {
    DoublyLinkedList list;
    dblListInit(&list);
    int data1 = 60, data2 = 70;
    dblListInsertAtEnd(&list, &data1, sizeof(data1));
    dblListInsertAtEnd(&list, &data2, sizeof(data2));
    cr_assert_eq(*(int*)list.tail->prev->data, data1, "Previous link of the last node is not correct");
    dblListFree(&list);
}

// Test for inserting after deleting a node
Test(doubly_linked_list, insertAfterDelete) {
    DoublyLinkedList list;
    dblListInit(&list);
    int data1 = 80, data2 = 90;
    dblListInsertAtEnd(&list, &data1, sizeof(data1));
    dblListDeleteNode(&list, &data1, compareInts);
    dblListInsertAtEnd(&list, &data2, sizeof(data2));
    cr_assert_eq(*(int*)list.head->data, data2, "Head data is not correct after insertion post deletion");
    dblListFree(&list);
}


