#include <stdio.h>
#include <stdlib.h>

typedef int DynArrType;
typedef unsigned int uint;
#define ASSERT_ALLOC(ptr) if (ptr == NULL) { \
    printf("Memory allocation failed\n"); \
    exit(1); \
  }

typedef struct {
    DynArrType * buffer;
    uint size;
    uint capacity;
  } DynamicArray;

void printDynArr(DynamicArray * dynArr) {
  for (int i = 0; i < dynArr->size; i++) {
    printf("%u ", dynArr->buffer[i]);
  }
  printf("\n");
}

void assertIndexInBounds(DynamicArray * dynArr, uint index) {
    if (index >= dynArr->size) {
      printf("Index out of bounds \n");
      exit(1);
    }
  }
  
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
  
    if (newArray.capacity > 0) {
      newArray.buffer = calloc(newArray.capacity, sizeof(DynArrType));
      ASSERT_ALLOC(newArray.buffer);
    }
  
    return newArray;
  }
  
static void resize(DynamicArray * dynArr, uint newSize) {
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
      DynArrType * temp = realloc(dynArr->buffer, dynArr->capacity * sizeof(DynArrType));
      ASSERT_ALLOC(temp);
      dynArr->buffer = temp;
    }
  
    dynArr->size = newSize;
  }
  
void pushBack(DynamicArray * dynArr, DynArrType value) {
    uint newSize = dynArr->size + 1;
    resize(dynArr, newSize);
    dynArr->buffer[newSize-1] = value;
  }
  
void push(DynamicArray * dynArr, uint index, DynArrType value) {
    assertIndexInBounds(dynArr, index);
    uint newSize = dynArr->size + 1;
    resize(dynArr, newSize);
    for (int i = newSize - 1; i > index; i--) {
      dynArr->buffer[i] = dynArr->buffer[i-1];
    }
    dynArr->buffer[index] = value;
  }
  
void pushFront(DynamicArray * dynArr, DynArrType value) {
    push(dynArr, 0, value);
  }
  
DynArrType popBack(DynamicArray * dynArr) {
    DynArrType result = dynArr->buffer[dynArr->size - 1];
    uint newSize = dynArr->size - 1;
    resize(dynArr, newSize);
  
    return result;
  }
  
DynArrType pop(DynamicArray * dynArr, uint index) {
    assertIndexInBounds(dynArr, index);
    uint newSize = dynArr->size - 1;
    DynArrType result = dynArr->buffer[index];
    for (int i = index; i < newSize; i++) {
      dynArr->buffer[i] = dynArr->buffer[i+1];
    }
    resize(dynArr, newSize);
    return result;
  }
  
DynArrType popFront(DynamicArray * dynArr) {
    return pop(dynArr, 0);
  }
  
DynArrType get(DynamicArray * dynArr, uint index) {
    assertIndexInBounds(dynArr, index);
    DynArrType element = dynArr->buffer[index];
    return element;
  }
  
void set(DynamicArray * dynArr, uint index, DynArrType value) {
    assertIndexInBounds(dynArr, index);
    dynArr->buffer[index] = value;
  }
  
void release(DynamicArray * dynArr) {
    free(dynArr->buffer);
    dynArr->buffer = NULL;
  
    dynArr->capacity = 0;
    dynArr->size = 0;
  }
  
DynArrType get_by_value(DynamicArray * dynArr, DynArrType value) {
      for (int i = 0; i < dynArr->size; i++) {
          if (dynArr->buffer[i] == value) {
          return i;
          }
      }
      return -1;
  }

int main(void) {

  DynamicArray dynArr = init(2);

  printf("New array size: %u\n", dynArr.size);
  printf("New array capacity: %u\n", dynArr.capacity);
  printf("New array buffer != NULL: %u\n", dynArr.buffer != NULL);

  pushBack(&dynArr, 10);
  pushBack(&dynArr, 15);
  pushBack(&dynArr, 20);

  printDynArr(&dynArr);

  push(&dynArr, 1, 100);
  printDynArr(&dynArr);

  pushFront(&dynArr, 77);
  printDynArr(&dynArr);

  DynArrType lastElement = popBack(&dynArr);
  printf("Last element %d\n", lastElement);
  printDynArr(&dynArr);

  DynArrType thirdElement = pop(&dynArr, 2);
  printf("Third element %d\n", thirdElement);
  printDynArr(&dynArr);

  DynArrType atSecondElement = get(&dynArr, 1);
  printf("Second element %d\n", atSecondElement);
  printDynArr(&dynArr);

  int value = 77;
  int result = get_by_value(&dynArr, value);
  printf("Index of %d: %d\n", value, result);

  release(&dynArr);
  
  printf("Release size: %u\n", dynArr.size);
  printf("Release capacity: %u\n", dynArr.capacity);
  printf("New array buffer == NULL: %u\n", dynArr.buffer == NULL);


}