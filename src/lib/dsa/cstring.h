#ifndef c_base_string_h
#define c_base_string_h

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    size_t length;
    char *data;
} String;

String* newString(const char* data);
void freeString(String* string);
char lastChar(String* string);
size_t stringLength(String* string);
bool equalStrings(String* stringA, String* stringB);
bool stringContainsChar(String* string, char c);
bool stringContains(String* string, const char* substring);

#endif
