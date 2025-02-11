#include "quadraticroots.h"
#include <math.h> 

QuadraticRootsResult findroots(long double a, long double b, long double c) {
    QuadraticRootsResult result;

    if (a == 0) {
        result.norealroots = true; 
        return result;
    }

    long double D = b * b - 4 * a * c;

    if (D < 0) {
        result.norealroots = true;
    } else {
        result.norealroots = false;
        long double sqrt_D = sqrtl(D);
        result.x1 = (-b + sqrt_D) / (2 * a);
        result.x2 = (-b - sqrt_D) / (2 * a);
    }

    return result;
}
