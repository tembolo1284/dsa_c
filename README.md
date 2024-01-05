# C Data Structures and Algorithms Library

## Overview

This repository is part of an ongoing project to implement various data structures and algorithms in C. The `linked_list` is the first data structure implemented, with more to come soon.

## Linked List Library

### `linked_list.c` and `linked_list.h`

The linked list implementation provides a generic way to create and manage a linked list, capable of storing data of any primitive data type.

#### Key Functions

- `initLinkedList(LinkedList* list)`: Initializes a new linked list.
- `insertAtBeg(LinkedList* list, void* data, size_t dataSize)`: Inserts a new node at the beginning of the list.
- `insertAtEnd(LinkedList* list, void* data, size_t dataSize)`: Inserts a new node at the end of the list.
- `deleteNode(LinkedList* list, void* data, size_t dataSize, int (*cmp)(void*, void*))`: Deletes a node from the list.
- `reverseList(LinkedList* list)`: Reverses the order of the nodes in the list.
- `freeLinkedList(LinkedList* list)`: Frees all nodes in the list.

#### Data Structures

- `Node`: Represents a node in the linked list.
- `LinkedList`: Represents the linked list itself.

### `utils.c` and `utils.h`

Utility functions for the linked list, including comparison and printing methods for different data types.

## Testing with `test_linked_list.c`

Unit tests are provided using the Criterion testing framework. They validate the functionality of the linked list through various test cases:

- **Initialization**: Tests if a new linked list is initialized correctly.
- **Insertion at Beginning**: Verifies correct insertion at the beginning.
- **Insertion at End**: Checks for correct insertion at the end of the list.
- **Deletion**: Ensures proper deletion functionality.
- **Reversal**: Validates the list reversal functionality.
- **Free List**: Confirms that the list is freed without memory leaks.

## Future Developments

- More data structures will be added to this library soon.
- Implementation of various algorithms is also planned.

## Compilation and Testing

To compile and test the library:

1. Run `make` to build the library and the main application.
2. Run `make test` to compile and execute the unit tests.

Ensure that Criterion is installed and properly set up in your environment for testing.

