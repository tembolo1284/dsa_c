#ifndef STACK_LL_H
#define STACK_LL_H

#include "linked_list.h"

typedef struct Stack {
    LinkedList list;
    size_t itemSize;
    int (*compare)(void*, void*);
} Stack;

// Function prototypes
Stack* stackInit_ll(size_t itemSize, int (*compare)(void*, void*));
void stackFree_ll(Stack* stack);
int stackPush_ll(Stack* stack, void* data);
int stackPop_ll(Stack* stack, void* out);
int stackPeek_ll(Stack* stack, void* out);
int isStackEmpty_ll(Stack* stack);

#endif // STACK_LL_H
