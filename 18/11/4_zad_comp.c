#include <stdio.h>
#include <math.h>

void pow_func(long arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = pow(arr[i], 4);  
    }
}

int main() {
    long arr[] = {2, 3, 4, 5};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    

    pow_func(arr, size);  

   
    for (size_t i = 0; i < size; i++) {
        printf("%ld ", arr[i]);
    }
    printf("\n");

    return 0;
}
