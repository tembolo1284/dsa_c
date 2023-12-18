#include "../include/stack_array.h"
#include <string.h>

Stack* stackInit(size_t capacity, size_t itemSize) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) return NULL;

    stack->items = malloc(capacity * sizeof(void*));
    if (!stack->items) {
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->top = -1;
    stack->itemSize = itemSize;

    return stack;
}

void stackFree(Stack* stack) {
    if (!stack) {
        return;
    }

    for (int i = 0; i <= stack->top; i++) {
        free(stack->items[i]);
    }

    free(stack->items);
    free(stack);
}

int push(Stack* stack, void* item) {
    if (isStackFull(stack)) {
        return 0;
    }

    void* newItem = malloc(stack->itemSize);
    if (!newItem) {
        return 0;
    }

    memcpy(newItem, item, stack->itemSize);
    stack->items[++stack->top] = newItem;
    return 1;
}

int pop(Stack* stack, void* out) {
    if (isStackEmpty(stack)) {
        return 0;
    }

    memcpy(out, stack->items[stack->top], stack->itemSize);
    free(stack->items[stack->top]);
    stack->top--;

    return 1;
}

int peek(Stack* stack, void* out) {
    if (isStackEmpty(stack)) {
        return 0;
    }

    memcpy(out, stack->items[stack->top], stack->itemSize);
    return 1;
}

bool isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isStackFull(Stack* stack) {
    return stack->top == (int)(stack->capacity - 1);
}
