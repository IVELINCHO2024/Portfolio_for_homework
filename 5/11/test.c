#include <stdio.h>

int main(void) {

  int * p1 = NULL;
  double * p2 = NULL;

  *p2 = 15;

  if (p2 == NULL) {
    printf("Pointer is null, so cannot dereference");
  } else {
    printf("Value: %lf", *p2);
  }

  return 0;
}