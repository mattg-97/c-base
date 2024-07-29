#ifndef c_base_string_h
#define c_base_string_h

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    size_t size;
    char *buffer;
} String;

typedef String Self;

String* newString(const char* data);
void freeString(Self* self);
char lastChar(Self* self);
size_t stringLength(Self* self);
bool equalStrings(String* stringA, String* stringB);
bool stringContainsChar(Self* self, char c);
bool stringContains(Self* self, const char* substring);
bool allocate(Self* self, size_t bytes);
void concat(Self* self, const char* data);
void insert(Self* self, const char* data, size_t index);


#endif
