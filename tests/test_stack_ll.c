#include <criterion/criterion.h>
#include <criterion/logging.h>
#include "../include/stack_ll.h"
#include "../include/utils.h"


// Test for stack initialization
Test(stack_ll, init) {
    Stack* stack = stackInit_ll(sizeof(int), compareInts);
    cr_assert_not_null(stack, "Stack initialization failed");
    cr_assert(isStackEmpty_ll(stack), "New stack should be empty");
    stackFree_ll(stack);
}

// Test for pushing and popping int
Test(stack_ll, push_pop_int) {
    Stack* stack = stackInit_ll(sizeof(int), compareInts);
    int val = 42;
    stackPush_ll(stack, &val);

    int out;
    cr_assert(stackPop_ll(stack, &out), "Pop failed");
    cr_assert(out == val, "Popped value doesn't match pushed value");

    stackFree_ll(stack);
}

// Test for pushing and popping char
Test(stack_ll, push_pop_char) {
    Stack* stack = stackInit_ll(sizeof(char), compareChars);
    char val = 'a';
    stackPush_ll(stack, &val);

    char out;
    cr_assert(stackPop_ll(stack, &out), "Pop failed");
    cr_assert(out == val, "Popped value doesn't match pushed value");

    stackFree_ll(stack);
}

// Test for peek functionality with int
Test(stack_ll, peek_int) {
    Stack* stack = stackInit_ll(sizeof(int), compareInts);
    int val = 99;
    stackPush_ll(stack, &val);

    int top;
    cr_assert(stackPeek_ll(stack, &top), "Peek failed");
    cr_assert(top == val, "Peeked value doesn't match pushed value");

    stackFree_ll(stack);
}

// Test for peek functionality with char
Test(stack_ll, peek_char) {
    Stack* stack = stackInit_ll(sizeof(char), compareInts);
    char val = 'z';
    stackPush_ll(stack, &val);

    char top;
    cr_assert(stackPeek_ll(stack, &top), "Peek failed");
    cr_assert(top == val, "Peeked value doesn't match pushed value");

    stackFree_ll(stack);
}

// Test for stack empty
Test(stack_ll, empty_test) {
    Stack* stack = stackInit_ll(sizeof(int), compareInts);
    cr_assert(isStackEmpty_ll(stack), "New stack should be empty");
    stackFree_ll(stack);
}
