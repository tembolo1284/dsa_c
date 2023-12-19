#include <criterion/criterion.h>
#include <criterion/logging.h>
#include "../include/queue.h"
#include "../include/utils.h"

// Test for queue initialization
Test(queue, init) {
    Queue* queue = queueInit(sizeof(int), compareInts);
    cr_assert_not_null(queue, "Queue initialization failed");
    cr_assert(isQueueEmpty(queue), "New queue should be empty");
    queueFree(queue);
}

// Test for enqueuing and dequeuing int
Test(queue, enqueue_dequeue_int) {
    Queue* queue = queueInit(sizeof(int), compareInts);
    int val = 42;
    enqueue(queue, &val);

    int out;
    cr_assert(dequeue(queue, &out), "Dequeue failed");
    cr_assert(out == val, "Dequeued value doesn't match enqueued value");

    queueFree(queue);
}

// Test for enqueuing and dequeuing char
Test(queue, enqueue_dequeue_char) {
    Queue* queue = queueInit(sizeof(char), compareChars);
    char val = 'a';
    enqueue(queue, &val);

    char out;
    cr_assert(dequeue(queue, &out), "Dequeue failed");
    cr_assert(out == val, "Dequeued value doesn't match enqueued value");

    queueFree(queue);
}

// Test for enqueuing and dequeuing double
Test(queue, enqueue_dequeue_double) {
    Queue* queue = queueInit(sizeof(double), compareDoubles);
    double val = 3.14159;
    enqueue(queue, &val);

    double out;
    cr_assert(dequeue(queue, &out), "Dequeue failed");
    cr_assert(out == val, "Dequeued value doesn't match enqueued value");

    queueFree(queue);
}

// Test for queue empty
Test(queue, empty_test) {
    Queue* queue = queueInit(sizeof(int), compareInts);
    cr_assert(isQueueEmpty(queue), "New queue should be empty");
    queueFree(queue);
}

