#include <stdlib.h>
#include "arraylist.h"

size_t getLength(ArrayList* list) {
    return list->length;
}

ArrayList* newArrayList() {
  ArrayList* this = (ArrayList*)malloc(sizeof(ArrayList));
  return this;
}
