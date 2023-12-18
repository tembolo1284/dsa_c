#include <criterion/criterion.h>
#include <criterion/logging.h>
#include "../include/stack_array.h"

// Test for stack initialization
Test(stack_array, init) {
    Stack* stack = stackInit(10, sizeof(double));
    cr_assert_not_null(stack, "Stack initialization failed");
    cr_assert(stack->top == -1, "Stack top should be -1 after initialization");
    cr_assert(stack->capacity == 10, "Stack capacity should be 10");
    stackFree(stack);
}

// Test for pushing and popping double
Test(stack_array, push_pop_double) {
    Stack* stack = stackInit(10, sizeof(double));
    double val = 3.14159;
    push(stack, &val);

    double out;
    cr_assert(pop(stack, &out), "Pop failed");
    cr_assert(out == val, "Popped value doesn't match pushed value");

    stackFree(stack);
}

// Test for pushing and popping char
Test(stack_array, push_pop_char) {
    Stack* stack = stackInit(10, sizeof(char));
    char val = 'a';
    push(stack, &val);

    char out;
    cr_assert(pop(stack, &out), "Pop failed");
    cr_assert(out == val, "Popped value doesn't match pushed value");

    stackFree(stack);
}

// Test for peek functionality
Test(stack_array, peek_test) {
    Stack* stack = stackInit(10, sizeof(double));
    double val = 2.71828;
    push(stack, &val);

    double top;
    cr_assert(peek(stack, &top), "Peek failed");
    cr_assert(top == val, "Peeked value doesn't match pushed value");

    stackFree(stack);
}

// Test for stack full
Test(stack_array, full_test) {
    Stack* stack = stackInit(1, sizeof(double));
    double val = 1.23;
    push(stack, &val);
    
    cr_assert(isStackFull(stack), "Stack should be full");

    stackFree(stack);
}

// Test for stack empty
Test(stack_array, empty_test) {
    Stack* stack = stackInit(10, sizeof(double));
    cr_assert(isStackEmpty(stack), "New stack should be empty");

    stackFree(stack);
}

