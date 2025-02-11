#include <stdio.h>
#include <string.h>
#include "mystrings.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <destination_string> <source_string>\n", argv[0]);
        return 1;
    }
    
    if (strlength(argv[1]) > MAX_STRING_LENGTH || 
        strlength(argv[2]) > MAX_STRING_LENGTH) {
        printf("Error: Strings must be 50 characters or less\n");
        return 1;
    }
    
    char result_string[MAX_STRING_LENGTH] = {0};
    strcpy(result_string, argv[1]);
    
    if (strconcat(result_string, argv[2]) == -1) { 
        printf("Error: Concatenation would exceed max string length\n");
        return 1;
    }
    
    printf("%s\n", result_string);
    
    return 0;
}