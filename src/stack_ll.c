#include "../include/stack_ll.h"
#include <string.h>
#include <utils.h>

Stack* stackInit_ll(size_t itemSize, int (*compare)(void*, void*)) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) return NULL;

    initList(&stack->list);
    stack->itemSize = itemSize;
    stack->compare = compare;
    return stack;
}

void stackFree_ll(Stack* stack) {
    if (stack) {
        freeList(&stack->list);
        free(stack);
    }
}

int stackPush_ll(Stack* stack, void* data) {
    // Since stack is LIFO, insert at the beginning
    insertAtBeg(&stack->list, data, stack->itemSize);
    return 1; // Assuming insertAtBeg always succeeds
}

int stackPop_ll(Stack* stack, void* out) {
    if (isStackEmpty_ll(stack)) {
        return 0;
    }
    
    // Copy the data from the head node
    memcpy(out, stack->list.head->data, stack->itemSize);

    // Delete the head node
    deleteNode(&stack->list, stack->list.head->data, stack->compare);
    return 1;
}

int stackPeek_ll(Stack* stack, void* out) {
    if (isStackEmpty_ll(stack)) {
        return 0;
    }

    // Copy the data from the head node
    memcpy(out, stack->list.head->data, stack->itemSize);
    return 1;
}

int isStackEmpty_ll(Stack* stack) {
    return stack->list.head == NULL;
}
