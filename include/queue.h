#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

typedef struct {
    LinkedList list;
    size_t itemSize;
    int (*compare)(void*, void*);
} Queue;

// Function prototypes
Queue* queueInit(size_t itemSize, int (*compare)(void*, void*));
void queueFree(Queue* queue);
int enqueue(Queue* queue, void* item);
int dequeue(Queue* queue, void* out);
int isQueueEmpty(Queue* queue);

#endif // QUEUE_H
