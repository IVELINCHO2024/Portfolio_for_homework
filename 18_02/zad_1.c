#include <stdio.h>

int main(){
    double a, b;
    scanf("%lf", &a);
    scanf("%lf", &b);
    double *p1 = &a;
    double *p2 = &b;

    printf("p(a) = %p a = %lf \np(b) = %p b = %lf", p1, *p1, p2, *p2);


    return 0;
}