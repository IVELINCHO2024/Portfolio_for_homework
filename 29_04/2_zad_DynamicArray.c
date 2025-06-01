#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASSERT_ALLOC(ptr) if (ptr == NULL) { \
    printf("Memory allocation failed\n"); \
    exit(1); \
  }

typedef int DynArrType;
typedef unsigned int uint;

typedef struct donor{
    char EGN[11];
} Donor;

typedef struct{
    Donor *buffer;
    uint size;
    uint capacity;
} DynamicArray;

DynamicArray init(uint capacity) {
    if (capacity < 0) {
        printf("Invalid capacity\n");
        exit(0);
    }

    DynamicArray newArray = {
        .size = 0,
        .capacity = capacity,
        .buffer = NULL
    };

    newArray.buffer = calloc(newArray.capacity, sizeof(Donor));
    ASSERT_ALLOC(newArray.buffer);
    return newArray;
}

void release(DynamicArray *dynArr) {
    free(dynArr->buffer);
    dynArr->buffer = NULL;
    
    dynArr->capacity = 0;
    dynArr->size = 0;
}

static void resize(DynamicArray *dynArr, uint newSize) {
    if (newSize > dynArr->capacity) {
        if (dynArr->capacity == 0) {
            dynArr->capacity = 1;
        }

        while (dynArr->capacity < newSize) {
            dynArr->capacity *= 2;
        }
    } else if (newSize <= dynArr->capacity / 2) {
        dynArr->capacity = newSize;
    }

    if (dynArr->capacity == 0) {
        free(dynArr->buffer);
        dynArr->buffer = NULL;
    } else {
        Donor *temp = realloc(dynArr->buffer, dynArr->capacity * sizeof(Donor));
        ASSERT_ALLOC(temp);
        dynArr->buffer = temp;
    }

    dynArr->size = newSize;
}

void addDonor(DynamicArray *dynArr, const char *egn) {
    uint newSize = dynArr->size + 1;
    resize(dynArr, newSize);

    strncpy(dynArr->buffer[dynArr->size - 1].EGN, egn, 10);
    dynArr->buffer[dynArr->size - 1].EGN[10] = '\0';
}

void removeDonor(DynamicArray *dynArr, const char *egn) {
    for (uint i = 0; i < dynArr->size; i++) {
        if (strcmp(dynArr->buffer[i].EGN, egn) == 0) {
            for (uint j = i; j < dynArr->size - 1; j++) {
                dynArr->buffer[j] = dynArr->buffer[j + 1];
            }
            resize(dynArr, dynArr->size - 1);
            return;
        }
    }
    printf("Donor not found.\n");
}

void printDonors(const DynamicArray *dynArr) {
    printf("List of donors:\n");
    for (uint i = 0; i < dynArr->size; i++) {
        printf("%s\n", dynArr->buffer[i].EGN);
    }
}

int main() {
    DynamicArray donors = init(2);

    int choice;
    char egn[11];

    do {
        printf("\nMenu:\n");
        printf("1.Add donor\n");
        printf("2.Remove donor\n");
        printf("3.Show all donors\n");
        printf("4.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the EGN of the donor: ");
                scanf("%10s", egn);
                addDonor(&donors, egn);
                break;
            case 2:
                printf("Enter EGN of donor to remove: ");
                scanf("%10s", egn);
                removeDonor(&donors, egn);
                break;
            case 3:
                printDonors(&donors);
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    release(&donors);
    return 0;
}