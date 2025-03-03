#include <stdio.h>

#define LINES 4


size_t lenght(const char *str) {
    const char *ptr = str; 
    
    while (*ptr != '\0') {
        ptr++; 
    }

  
    return ptr - str;
}


void swap(void *a, void *b){
    int temp = *(int *)a;
    *(int *)a = *(int *)b;
    *(int *)b = temp;
}


void sort(int *arr, size_t size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (*(arr + j) < *(arr + i)) {
                swap(arr + i, arr + j); 
            }
        }
    }
}

void strhalf(const char *str, char **half) {
    size_t len = lenght(str);
    *half = (char *)(str + len / 2); 
}


void print_matrix(int (*matrix)[LINES], size_t rows) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < LINES; ++j) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

int main() {
    const char *text = "You are a student";
    printf("Length: %zu\n", lenght(text));

    int arr[] = {5, 2, 9, 1, 6};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    sort(arr, size);

    printf("Sorted arr: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    char *half = NULL;
    strhalf(text, &half);
    printf("Second half: %s\n", half);

    int two_d_arr[3][LINES] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    printf("Two_d_arr:\n");
    print_matrix(two_d_arr, 3);

    return 0;
}
