#include <criterion/criterion.h>
#include <criterion/logging.h>
#include "../include/hashmap.h"
#include "../include/utils.h"

// Test for hashmap initialization
Test(hashmap, init) {
    Hashmap *map = hashmapInit(10, sizeof(int), sizeof(int), hashInt, compareInts, allocInt, allocInt, freeInt, freeInt);
    cr_assert_not_null(map, "Hashmap initialization failed");
    cr_assert_eq(hashmapSize(map), 0, "New hashmap should be empty");
    hashmapFree(map);
}

// Test for inserting and getting int values
Test(hashmap, insert_get_int) {
    Hashmap *map = hashmapInit(10, sizeof(int), sizeof(int), hashInt, compareInts, allocInt, allocInt, freeInt, freeInt);
    int key = 1;
    int value = 42;

    cr_assert(hashmapInsert(map, &key, &value), "Insert failed");
    int retrieved;
    cr_assert(hashmapGet(map, &key, &retrieved), "Get failed");
    cr_assert_eq(retrieved, value, "Retrieved value doesn't match inserted value");

    hashmapFree(map);
}

// Test for inserting and getting char values
Test(hashmap, insert_get_char) {
    Hashmap *map = hashmapInit(10, sizeof(char), sizeof(char), hashChar, compareChars, allocChar, allocChar, freeChar, freeChar);
    char key = 'a';
    char value = 'n';

    cr_assert(hashmapInsert(map, &key, &value), "Insert failed");
    char retrieved;
    cr_assert(hashmapGet(map, &key, &retrieved), "Get failed");
    cr_assert_eq(retrieved, value, "Retrieved value doesn't match inserted value");

    hashmapFree(map);
}

// Test for removing elements
Test(hashmap, remove) {
    Hashmap *map = hashmapInit(10, sizeof(int), sizeof(int), hashInt, compareInts, allocInt, allocInt, freeInt, freeInt);
    int key = 1;
    int value = 42;

    hashmapInsert(map, &key, &value);
    cr_assert(hashmapRemove(map, &key), "Remove failed");
    cr_assert_eq(hashmapSize(map), 0, "Hashmap should be empty after removal");

    hashmapFree(map);
}

// Test for hashmap size
Test(hashmap, size) {
    Hashmap *map = hashmapInit(10, sizeof(int), sizeof(int), hashInt, compareInts, allocInt, allocInt, freeInt, freeInt);
    int key = 1, key2 = 2;
    int value = 42, value2 = 24;

    hashmapInsert(map, &key, &value);
    hashmapInsert(map, &key2, &value2);
    cr_assert_eq(hashmapSize(map), 2, "Hashmap size should be 2");

    hashmapFree(map);
}

