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

#endif // UTILS_H
