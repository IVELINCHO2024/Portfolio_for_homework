#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareasc(const void *a, const void *b){
    int a1 = *(int *)a;
    int b1 = *(int *)b;

    if(a1>b1){
        return 1;
    }
    if(b1>a1){
        return -1;
    }
        return 0;
}

int comparedesc(const void *a, const void *b) {
    int int_a = *( int *)a;
    int int_b = *( int *)b;
    if (int_a < int_b) return 1;
    if (int_a > int_b) return -1;
    return 0;
}

int main() {
    int arr[] = {5, 2, 9, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, size, sizeof(int), compareasc);
    printf("Ascending order: ");
    printArray(arr, size);

    qsort(arr, size, sizeof(int), comparedesc);
    printf("Descending order: ");
    printArray(arr, size);

    return 0;
}
