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

def parse_xml_to_deal(xml_data: str):
    # Parse the XML data
    root = ET.fromstring(xml_data)

    # Iterate over each 'Deal' element in the XML
    for deal_element in root.findall('.//Deal'):
        # Extract Deal data
        deal_id = deal_element.find('./id').text
        agreement_date = deal_element.find('./agreementDate').text
        facilities = []

        # Iterate over each 'Facility' within the Deal
        for facility_element in deal_element.findall('.//Facility'):
            # Extract Facility data
            facility_id = facility_element.find('./id').text
            expiration_date = facility_element.find('./expirationDate').text
            maturity_date = facility_element.find('./maturityDate').text
            active_outstandings = []

            # Iterate over each 'ActiveOutstanding' within the Facility
            for ao_element in facility_element.findall('.//ActiveOutstanding'):
                # Extract ActiveOutstanding data
                ao_id = ao_element.find('./id').text
                outstanding_type = ao_element.find('./outstandingType').text
                # ... continue extracting other fields

                portfolio_shares = []

                # Iterate over each 'PortfolioShare' within the ActiveOutstanding
                for ps_element in ao_element.findall('.//PortfolioShare'):
                    # Extract PortfolioShare data
                    portfolio_code = ps_element.find('./portfolioCode').text
                    amount = ps_element.find('./amount').text
                    # ... continue extracting other fields

                    # Create a PortfolioShare object
                    portfolio_share = PortfolioShare(portfolio_code=portfolio_code, amount=amount)
                    portfolio_shares.append(portfolio_share)

                # Create an ActiveOutstanding object
                active_outstanding = ActiveOutstanding(id=ao_id, outstanding_type=outstanding_type, portfolio_shares=portfolio_shares)
                active_outstandings.append(active_outstanding)

            # Create a Facility object
            facility = Facility(id=facility_id, expiration_date=expiration_date, maturity_date=maturity_date, active_outstandings=active_outstandings)
            facilities.append(facility)

        # Create a Deal object
        deal = Deal(id=deal_id, agreement_date=agreement_date, facilities=facilities)
        yield deal
