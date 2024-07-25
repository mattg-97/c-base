#ifndef c_base_arraylist_h
#define c_base_arraylist_h

#include <stddef.h>

typedef struct arrayList{
    size_t length;
} ArrayList;

size_t getLength(ArrayList* self);
ArrayList* newArrayList();


#endif
