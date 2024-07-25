#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "cstring.h"

String* newString(const char *data) {
    String* s = (String*)malloc(sizeof(String));
    if (s == NULL) {
        return NULL;
    }
    s->length = strlen(data);
    s->data = malloc(s->length + 1);
    if (s->data == NULL) {
        free(s);
        return NULL;
    }
    strcpy(s->data, data);
    return s;
}

char lastChar(String* string) {
    return string->data[string->length];
}

size_t stringLength(String *string) {
    if (string != NULL) {
        return string->length;
    }
    return 0;
}

bool equalStrings(String *stringA, String *stringB) {
    if (stringA == NULL && stringB == NULL) return false;
    if (stringA == NULL || stringB == NULL) return false;
    if (stringA->data == NULL || stringB->data == NULL) return false;
    if (stringA->length != stringB->length) return false;
    for (int i = 0; i < stringA->length; i++) {
        if (stringA->data[i] != stringB->data[i]) return false;
    }
    return true;
}

void freeString(String *string) {
    if (string != NULL) {
        free(string->data);
        free(string);
    }
}
