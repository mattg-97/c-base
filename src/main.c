#include <stdio.h>
#include "lib/dsa/cstring.h"

int main(void) {
    String* my_string = newString("Hello world!");
    char last_char = lastChar(my_string);
    printf("Last char: %c\n", last_char);
    freeString(my_string);
    return 0;
}
