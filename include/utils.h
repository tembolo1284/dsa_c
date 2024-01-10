#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

// Integer functions
int compareInts(void* a, void* b);
void printInt(void* data);

// Char functions
int compareChars(void* a, void* b);
void printChar(void* data);

// Float functions
int compareFloats(void* a, void* b);
void printFloat(void* data);

// Double functions
int compareDoubles(void* a, void* b);
void printDouble(void* data);

// Hash functions
unsigned int hashInt(const void *key);
unsigned int hashChar(const void *key);
unsigned int hashFloat(const void *key);
unsigned int hashDouble(const void *key);

// Allocation and deallocation functions
void allocInt(void *dest, const void *src);
void freeInt(void *ptr);
void allocChar(void *dest, const void *src);
void freeChar(void *ptr);
void allocFloat(void *dest, const void *src);
void freeFloat(void *ptr);
void allocDouble(void *dest, const void *src);
void freeDouble(void *ptr);
#endif // UTILS_H
