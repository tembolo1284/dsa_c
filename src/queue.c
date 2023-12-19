#include "../include/queue.h"
#include "../include/utils.h"
#include <string.h>

Queue* queueInit(size_t itemSize, int (*compare)(void*, void*)) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) return NULL;

    initList(&queue->list);
    queue->itemSize = itemSize;
    queue->compare =compare;
    return queue;
}

void queueFree(Queue* queue) {
    if (queue) {
        freeList(&queue->list);
        free(queue);
    }
}

int enqueue(Queue* queue, void* item) {
    insertAtEnd(&queue->list, item, queue->itemSize);
    return 1; // Assuming insertAtEnd always succeeds
}

int dequeue(Queue* queue, void* out) {
    if (isQueueEmpty(queue)) {
        return 0;
    }

    Node* headNode = queue->list.head;
    if (headNode) {
        memcpy(out, headNode->data, queue->itemSize);
        deleteNode(&queue->list, headNode->data, queue->compare); // NULL comparison function, assuming direct deletion of head
        return 1;
    }
    return 0;
}

int isQueueEmpty(Queue* queue) {
    return queue->list.head == NULL;
}

