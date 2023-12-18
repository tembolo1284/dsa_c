#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void **items;     // Array of pointers to hold items of any type
    size_t capacity;  // Maximum number of items that can be held
    int top;          // Index of the top item in the stack
    size_t itemSize;  // Size of each item in bytes
} Stack;

// Function prototypes
Stack* stackInit(size_t capacity, size_t itemSize);
void stackFree(Stack* stack);
int push(Stack* stack, void* item);
int pop(Stack* stack, void* out);
int peek(Stack* stack, void* out);
bool isStackEmpty(Stack* stack);
bool isStackFull(Stack* stack);

#endif // STACK_ARRAY_H
