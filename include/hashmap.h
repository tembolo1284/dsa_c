#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdlib.h>

typedef struct KeyValue {
    void *key;
    void *value;
} KeyValue;

typedef struct Node {
    KeyValue data;
    struct Node *next;
} Node;

typedef struct Hashmap {
    Node **buckets;
    int size;
    int capacity;
    size_t key_size;
    size_t value_size;
    unsigned int (*hash_function)(const void *);
    int (*key_compare)(void *, void *);
    void (*key_alloc)(void *, const void *);
    void (*value_alloc)(void *, const void *);
    void (*key_free)(void *);
    void (*value_free)(void *);
} Hashmap;

// Function declarations
Hashmap *hashmapInit(int capacity, size_t key_size, size_t value_size, 
                       unsigned int (*hash_function)(const void *),
                       int (*key_compare)(void *, void *),
                       void (*key_alloc)(void *, const void *),
                       void (*value_alloc)(void *, const void *),
                       void (*key_free)(void *),
                       void (*value_free)(void *));
void hashmapFree(Hashmap *map);
int hashmapInsert(Hashmap *map, void *key, const void *value);
int hashmapGet(Hashmap *map, void *key, void *value);
int hashmapRemove(Hashmap *map, void *key);
int hashmapSize(Hashmap *map);

#endif

