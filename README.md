# C Data Structures and Algorithms Library

## Overview

This repository contains a comprehensive library implementing various data structures and algorithms in C. It provides a generic way to handle different data types and includes a suite of operations for each data structure.

## Data Structures

### Linked List (`linked_list.c`, `linked_list.h`)
- **Key Functions:** Initialize, insert, delete, reverse, and free a linked list.
- **Data Structures:** `Node`, `LinkedList`.

### Hashmap (`hashmap.c`, `hashmap.h`)
- **Key Functions:** Initialize, insert, get, remove, and free a hashmap.
- **Data Structures:** `KeyValue`, `Node`, `Hashmap`.

### Queue (`queue.c`, `queue.h`)
- **Key Functions:** Initialize, enqueue, dequeue, and check if empty.
- **Data Structures:** `Queue`.

### Stack (Array-based) (`stack_array.c`, `stack_array.h`)
- **Key Functions:** Initialize, push, pop, peek, and check if empty.
- **Data Structures:** `Stack` (array-based implementation).

### Stack (Linked List-based) (`stack_ll.c`, `stack_ll.h`)
- **Key Functions:** Initialize, push, pop, peek, and check if empty.
- **Data Structures:** `Stack` (linked list-based implementation).

### Node (`node.c`, `node.h`)
- **Purpose:** Fundamental building block used in several of the above data structures.

## Utility Library (`utils.c`, `utils.h`)
Includes comparison and printing methods for different data types to support the data structures.

## Unit Testing (`test_linked_list.c`)
- **Framework:** Criterion testing framework.
- **Tests:** Initialization, insertion, deletion, reversal, and memory management.

## Future Developments
- Continuous expansion with more data structures and algorithms.
- Enhancements to existing implementations.

## Compilation and Testing
- **Build:** Run `make` to compile the library and main application.
- **Unit Tests:** Run `make test` for executing unit tests (requires Criterion).

---

