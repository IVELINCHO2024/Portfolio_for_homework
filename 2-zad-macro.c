#include <stdio.h>
#define TROICHNO(A, B) ((A) > (B) ? (A) : (B))


int main() {
    int a = 10, b = 20;
    int max = TROICHNO(a, b);
    printf("max of this numbers is: %d\n", max);
    return 0;
}
