#ifndef DBL_NODE_H
#define DBL_NODE_H

#include <stdlib.h>

typedef struct Dbl_Node {
    void* data;
    struct Dbl_Node* next;
    struct Dbl_Node* prev;
} Dbl_Node;

Dbl_Node* dblNodeCreate(void* data, size_t dataSize);
void dblNodeFree(Dbl_Node* node);

#endif //DBL_NODE_H
