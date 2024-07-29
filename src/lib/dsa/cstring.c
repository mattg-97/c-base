#include "cstring.h"
#include <string.h>

String* newString(const char *data) {
    String* s = (String*)malloc(sizeof(String));
    if (s == NULL) {
        return NULL;
    }
    s->size = 0;
    s->size = strlen(data);
    s->buffer = NULL;
    s->buffer = malloc(s->size + 1);
    if (s->buffer == NULL) {
        free(s);
        return NULL;
    }
    strcpy(s->buffer, data);
    return s;
}

char lastChar(Self* self) {
    return self->buffer[self->size - 1];
}

size_t stringLength(Self *self) {
    if (self != NULL) {
        return self->size;
    }
    return 0;
}

bool equalStrings(String *stringA, String *stringB) {
    if (stringA == NULL && stringB == NULL) return true;
    if (stringA == NULL || stringB == NULL) return false;
    if (stringA->buffer == NULL || stringB->buffer == NULL) return false;
    if (stringA->size != stringB->size) return false;
    for (int i = 0; i < stringA->size; i++) {
        if (stringA->buffer[i] != stringB->buffer[i]) return false;
    }
    return true;
}

void freeString(Self *self) {
    if (self != NULL) {
        free(self->buffer);
        free(self);
    }
}

bool allocate(Self *self, size_t bytes) {
    if (self->buffer != NULL) {
        if (bytes < self->size) self->size = bytes;
        self->buffer = realloc(self->buffer, bytes);
    } else{
        self->buffer = (char*)malloc(bytes);
    }
    if (self->buffer == NULL) {
        return false;
    }
    return true;
}

void insert(Self* self, const char* data, size_t index) {
    if (self->buffer != NULL) {
        if (self->size + (size_t)strlen(data) > (size_t)strlen(self->buffer)) {
            if (!allocate(self, (self->size + (size_t)strlen(data)) * 2)) {
                printf("unable to allocate\n");
            }
        }
    } else {
        if (!allocate(self, ((size_t)strlen(data)) * 2)) {
            printf("unable to allocate\n");
        }
    }

    char* buffer = self->buffer;

    if (index == self->size) {
        size_t i = 0;
        while (i < (size_t)strlen(data)) {
            buffer[self->size + i] = data[i];
            i++;
        }
    }
    self->size += (size_t)strlen(data);
}

void concat(Self* self, const char* data) {
    insert(self, data, (size_t)strlen(data));
}
