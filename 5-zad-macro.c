#include <stdio.h>

// Макро за размяна на стойности на две променливи от произволен тип
#define SWAP(A, B, TYPE) \
    do {                 \
        TYPE C = A;   \
        A = B;           \
        B = C;        \
    } while (0)

int main() {
    int a = 5, b = 10;
   
    SWAP(a, b, int);
    printf("switching: a = %d, b = %d\n", a, b);

    
    return 0;
}
