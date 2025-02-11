#include <stdio.h>



void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i+1; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int c = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = c;
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int z = arr[i];
        arr[i] = arr[size - i - 1];
        arr[n - i - 1] = z;
    }
}

void sortArray(int arr[], int n) {
#if defined(_WIN32) || defined(_WIN64)
    bubbleSort(arr, n);
#elif defined(__linux__)
    selectionSort(arr, n);
#elif defined(__APPLE__)
    insertionSort(arr, n);
#else
    reverseArray(arr, n);
#endif
}



int main() {
    int arr[] = { 3,4,12,6,43,88,9 };
    int size = sizeof(arr) / sizeof(arr[0]);
  
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    return 0;
}
