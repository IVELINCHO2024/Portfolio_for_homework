#include <stdio.h>

void bubblesort(void *arr, size_t n, size_t size, int (*compare)(const void *, const void *), void (*swapelements)(void *, void *)) {
    char *array = (char *)arr;

    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (compare(array + j * size, array + (j + 1) * size) > 0) {
                swapelements(array + j * size, array + (j + 1) * size);
            }
        }
    }
}


int compare_int_asc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


int compareasc(const void *a, const void *b) {
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;
    if (int_a > int_b) return 1;
    if (int_a < int_b) return -1;
    return 0;
}


int comparedesc(const void *a, const void *b) {
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;
    if (int_a < int_b) return 1;
    if (int_a > int_b) return -1;
    return 0;
}


void swap_ints(void *a, void *b) {
    int temp = *(int *)a;
    *(int *)a = *(int *)b;
    *(int *)b = temp;
}


int main() {
    int arr[] = {5,9,7,4,2,3};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    printf("Ascending order:\n");
    bubblesort(arr, n, sizeof(int), compareasc, swap_ints);
    for (size_t i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int arr2[] = {5, 2, 9, 1, 6};
    printf("Descending order:\n");
    bubblesort(arr2, n, sizeof(int), comparedesc, swap_ints);
    for (size_t i = 0; i < n; ++i) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}