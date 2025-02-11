#include <stdio.h>
#include "mystrings.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <first_string> <second_string>\n", argv[0]);
        return 1;
    }
    
    int comparison_result = strcompare(argv[1], argv[2]);
    printf("%d\n", comparison_result);
    
    return 0;
}