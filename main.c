#include <stdio.h>
#include "linked_list.h"
#include "utils.h"

int main() {
    LinkedList list;
    initList(&list);

    // Testing with integers
    int data1 = 10, data2 = 20, data3 = 30;
    int someData = 888;
    insertAtEnd(&list, &data1, sizeof(int));
    insertAtEnd(&list, &data2, sizeof(int));
    insertAtEnd(&list, &data3, sizeof(int));

    printf("List after inserting integers: ");
    printList(&list, printInt);
    printf("\n");

    deleteNode(&list, &data2, compareInts);
    printf("List after deleting an integer: ");
    printList(&list, printInt);
    printf("\n");

    insertAtBeg(&list, &someData, sizeof(someData));

    // Reversing the list
    reverseList(&list);
    printf("Reversed list: ");
    printList(&list, printInt);
    printf("\n");

    freeList(&list);

    // Testing with characters
    char char1 = 'a', char2 = 'b', char3 = 'c';
    initList(&list);
    insertAtEnd(&list, &char1, sizeof(char));
    insertAtEnd(&list, &char2, sizeof(char));
    insertAtEnd(&list, &char3, sizeof(char));

    printf("List after inserting characters: ");
    printList(&list, printChar);
    printf("\n");

    deleteNode(&list, &char2, compareChars);
    printf("List after deleting a character: ");
    printList(&list, printChar);
    printf("\n");

    reverseList(&list);
    printf("Reversed list: ");
    printList(&list, printChar);
    printf("\n");

    freeList(&list);

    // Testing with floats
    float float1 = 1.1f, float2 = 2.2f, float3 = 3.3f;
    initList(&list);
    insertAtEnd(&list, &float1, sizeof(float));
    insertAtEnd(&list, &float2, sizeof(float));
    insertAtEnd(&list, &float3, sizeof(float));

    printf("List after inserting floats: ");
    printList(&list, printFloat);
    printf("\n");

    deleteNode(&list, &float2, compareFloats);
    printf("List after deleting a float: ");
    printList(&list, printFloat);
    printf("\n");

    reverseList(&list);
    printf("Reversed list: ");
    printList(&list, printFloat);
    printf("\n");

    freeList(&list);

    return 0;
}
