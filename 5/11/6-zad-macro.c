#include <stdio.h>


#define SWAP(A, B, TYPE) \
    do {                 \
        TYPE C = A;   \
        A = B;           \
        B = C;        \
    } while (0)


#define SORT(ARR, SIZE, TYPE, COMPARE)         \
    do {                                         \
        for (int i = 0; i < SIZE - 1; i++) {     \
            for (int j = i + 1; j < SIZE; j++) { \
                if (ARR[i] COMPARE ARR[j]) { \
                    SWAP(ARR[i], ARR[j], TYPE); \
                }                                \
            }                                    \
        }                                        \
    } while (0)

int main() {
    int arr[] = {4, 5, 7, 9, 10, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    SORT(arr, size, int, >);
    
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    
    SORT(arr, size, int, <);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
