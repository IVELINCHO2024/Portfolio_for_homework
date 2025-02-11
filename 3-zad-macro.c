#include <stdio.h>
#define MACRO(A) \
printf("File: %s, Line: %d, Variable: %s, Value: %d\n",  \
__FILE__, __LINE__, #A, A) \

int main() {
    int a=5;
    MACRO(a);
    return 0;
}
