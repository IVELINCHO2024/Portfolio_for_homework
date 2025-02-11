#include <stdio.h>
#include "quadraticroots.h"

void display_result(QuadraticRootsResult result) {
    if (result.norealroots) {
        printf("The equation has no real roots.\n");
    } else {
        printf("Roots: x1 = %Lf, x2 = %Lf\n", result.x1, result.x2);
    }
}

int main() {
    printf("Testing with int arguments:\n");
    QuadraticRootsResult res1 = findroots(1, -3, 2);
    display_result(res1);

    printf("Testing with float arguments:\n");
    QuadraticRootsResult res2 = findroots(1.0f, -3.0f, 2.0f);
    display_result(res2);

    printf("Testing with double arguments:\n");
    QuadraticRootsResult res3 = findroots(1.0, -2.0, 1.0); 
    display_result(res3);

    return 0;
}