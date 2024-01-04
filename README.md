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


from typing import Generator
import xml.etree.ElementTree as ET
from collections import OrderedDict

# Assume Facility and Deal are defined somewhere with the proper structure
# to handle **facility_data and **deal_data respectively

def get_deals_from_file(filename: str) -> Generator[Deal, None, None]:
    # Parse the XML file
    tree = ET.parse(filename)
    root = tree.getroot()
    
    # Iterate over each 'Deal' element in the XML
    for deal_element in root.findall('.//Deal'):
        deal_data = {}
        
        # Extract data for the deal
        for child in deal_element:
            if child.tag == 'Facilities':
                facilities = []
                for facility_element in child.findall('.//Facility'):
                    facility_data = {}
                    active_outstandings = []
                    for facility_child in facility_element:
                        if facility_child.tag == 'ActiveOutstandings':
                            for ao in facility_child.findall('.//ActiveOutstanding'):
                                active_outstanding_data = {}
                                portfolio_shares = []
                                for ao_child in ao:
                                    if ao_child.tag == 'PortfolioShares':
                                        for ps in ao_child.findall('.//PortfolioShare'):
                                            portfolio_shares.append(OrderedDict(ps.attrib))
                                    else:
                                        active_outstanding_data[ao_child.tag] = ao_child.text
                                active_outstandings.append(ActiveOutstanding(**active_outstanding_data, portfolio_shares=portfolio_shares))
                        else:
                            facility_data[facility_child.tag] = facility_child.text
                    facilities.append(Facility(**facility_data, active_outstandings=active_outstandings))
            else:
                deal_data[child.tag] = child.text
        yield Deal(**deal_data, facilities=facilities)

# Use the generator
for deal in get_deals_from_file('your_file.xml'):
    print(deal)  # Or process the deal object as needed


