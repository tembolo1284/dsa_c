#include "hashmap.h"
#include <string.h>

Hashmap *hashmapInit(int capacity, size_t key_size, size_t value_size, 
                       unsigned int (*hash_function)(const void *),
                       int (*key_compare)(void *, void *),
                       void (*key_alloc)(void *, const void *),
                       void (*value_alloc)(void *, const void *),
                       void (*key_free)(void *),
                       void (*value_free)(void *)) {
    Hashmap *map = malloc(sizeof(Hashmap));
    if (!map) return NULL;

    map->capacity = capacity;
    map->size = 0;
    map->key_size = key_size;
    map->value_size = value_size;
    map->hash_function = hash_function;
    map->key_compare = key_compare;
    map->key_alloc = key_alloc;
    map->value_alloc = value_alloc;
    map->key_free = key_free;
    map->value_free = value_free;

    map->buckets = calloc(capacity, sizeof(Node *));
    if (!map->buckets) {
        free(map);
        return NULL;
    }

    return map;
}

void destroyNode(Node *node, void (*key_free)(void *), void (*value_free)(void *)) {
    if (node) {
        destroyNode(node->next, key_free, value_free);
        key_free(node->data.key);
        value_free(node->data.value);
        free(node);
    }
}

void hashmapFree(Hashmap *map) {
    for (int i = 0; i < map->capacity; i++) {
        destroyNode(map->buckets[i], map->key_free, map->value_free);
    }
    free(map->buckets);
    free(map);
}

int hashmapInsert(Hashmap *map, void *key, const void *value) {
    unsigned int index = map->hash_function(key) % map->capacity;
    Node *node = map->buckets[index];

    // Check if key already exists
    while (node) {
        if (map->key_compare(node->data.key, key) == 0) {
            map->value_free(node->data.value);
            map->value_alloc(node->data.value, value); // Update value
            return 1;
        }
        node = node->next;
    }

    // Insert new key-value pair
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) return 0;

    newNode->data.key = malloc(map->key_size);
    newNode->data.value = malloc(map->value_size);
    if (!newNode->data.key || !newNode->data.value) {
        free(newNode->data.key);
        free(newNode->data.value);
        free(newNode);
        return 0;
    }

    map->key_alloc(newNode->data.key, key);
    map->value_alloc(newNode->data.value, value);

    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
    map->size++;

    return 1;
}

int hashmapGet(Hashmap *map, void *key, void *value) {
    unsigned int index = map->hash_function(key) % map->capacity;
    Node *node = map->buckets[index];

    while (node) {
        if (map->key_compare(node->data.key, key) == 0) {
            memcpy(value, node->data.value, map->value_size);
            return 1;
        }
        node = node->next;
    }

    return 0;
}

int hashmapRemove(Hashmap *map, void *key) {
    unsigned int index = map->hash_function(key) % map->capacity;
    Node *node = map->buckets[index];
    Node *prev = NULL;

    while (node) {
        if (map->key_compare(node->data.key, key) == 0) {
            if (prev) {
                prev->next = node->next;
            } else {
                map->buckets[index] = node->next;
            }
            map->key_free(node->data.key);
            map->value_free(node->data.value);
            free(node);
            map->size--;
            return 1;
        }
        prev = node;
        node = node->next;
    }

    return 0;
}

int hashmapSize(Hashmap *map) {
    return map->size;
}

