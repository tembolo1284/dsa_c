#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct Node {

  void* data;
  struct Node* next;

} Node;

Node* createNode(void* data, size_t dataSize);

void freeNode(Node* node);


#endif //NODE_H
