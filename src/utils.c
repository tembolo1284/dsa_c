/* utils.c */

#include "utils.h"

// Integer functions
int compareInts(void* a, void* b) {
    return *(int*)a - *(int*)b;
}

void printInt(void* data) {
    printf("%d ", *(int*)data);
}

// Char functions
int compareChars(void* a, void* b) {
    return *(char*)a - *(char*)b;
}

void printChar(void* data) {
    printf("%c ", *(char*)data);
}

// Float functions
int compareFloats(void* a, void* b) {
    float diff = *(float*)a - *(float*)b;
    return (diff > 0) - (diff < 0);
}

void printFloat(void* data) {
    printf("%f ", *(float*)data);
}

// Double functions
int compareDoubles(void* a, void* b) {
    double diff = *(double*)a - *(double*)b;
    return (diff > 0) - (diff < 0);
}

void printDouble(void* data) {
    printf("%lf ", *(double*)data);
}

// Hash functions
unsigned int hashInt(const void *key) {
    return *(const int *)key;
}

unsigned int hashChar(const void *key) {
    return *(const char *)key;
}

unsigned int hashFloat(const void *key) {
    // Hashing float by reinterpreting its bits as an int
    float key_f = *(const float *)key;
    int key_i = *(int *)&key_f;
    return key_i;
}

unsigned int hashDouble(const void *key) {
    // Hashing double with a simple method; may be improved for better distribution
    double key_d = *(const double *)key;
    return (unsigned int)(key_d);
}

// Allocation and deallocation functions for int
void allocInt(void *dest, const void *src) {
    *(int *)dest = *(const int *)src;
}

void freeInt(void *ptr) {
    // No special action needed for primitive types
    (void)ptr;
}

// Allocation and deallocation functions for char
void allocChar(void *dest, const void *src) {
    *(char *)dest = *(const char *)src;
}

void freeChar(void *ptr) {
    // No special action needed for primitive types
    (void)ptr;
}

// Allocation and deallocation functions for float
void allocFloat(void *dest, const void *src) {
    *(float *)dest = *(const float *)src;
}

void freeFloat(void *ptr) {
    // No special action needed for primitive types
    (void)ptr;
}

// Allocation and deallocation functions for double
void allocDouble(void *dest, const void *src) {
    *(double *)dest = *(const double *)src;
}

void freeDouble(void *ptr) {
    // No special action needed for primitive types
    (void)ptr;
}
