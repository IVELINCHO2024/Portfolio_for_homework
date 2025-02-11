#include <stdio.h>
#include "mystrings.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }
    
    int string_length = strlength(argv[1]);
    printf("%d\n", string_length);
    
    return 0;
}