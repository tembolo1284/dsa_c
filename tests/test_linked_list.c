#include <criterion/criterion.h>
#include <criterion/logging.h>
#include "../include/linked_list.h"
#include "../include/utils.h"

// Test case for linked list initialization
Test(linked_list, initialization) {
    LinkedList list;
    initList(&list);
    cr_assert_null(list.head, "LinkedList head should be NULL after initialization");
}

// Test case for inserting at the beginning
Test(linked_list, insertAtBeg) {
    LinkedList list;
    initList(&list);
    int data = 10;
    insertAtBeg(&list, &data, sizeof(data));
    cr_assert_not_null(list.head, "Head should not be NULL after insertion");
    cr_assert_eq(*(int*)list.head->data, data, "Data at the head is not correct after insertion");
    freeList(&list);
}

// Test case for inserting at the end
Test(linked_list, insertAtEnd) {
    LinkedList list;
    initList(&list);
    int data = 20;
    insertAtEnd(&list, &data, sizeof(data));
    cr_assert_not_null(list.head, "Head should not be NULL after insertion");
    cr_assert_eq(*(int*)list.head->data, data, "Data at the head is not correct after insertion");
    freeList(&list);
}

// Test case for deleting a node
Test(linked_list, deleteNode) {
    LinkedList list;
    initList(&list);
    int data = 30;
    insertAtEnd(&list, &data, sizeof(data));
    deleteNode(&list, &data, compareInts);
    cr_assert_null(list.head, "Head should be NULL after deletion");
    freeList(&list);
}

// Test case for reversing the list
Test(linked_list, reverseList) {
    LinkedList list;
    initList(&list);
    int data1 = 40, data2 = 50;
    insertAtEnd(&list, &data1, sizeof(data1));
    insertAtEnd(&list, &data2, sizeof(data2));
    reverseList(&list);
    cr_assert_eq(*(int*)list.head->data, data2, "Head data is not correct after reversal");
    cr_assert_eq(*(int*)list.head->next->data, data1, "Second node data is not correct after reversal");
    freeList(&list);
}
