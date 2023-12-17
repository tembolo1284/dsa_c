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

