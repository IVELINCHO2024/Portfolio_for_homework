#include <stdio.h>


void swap(void *a, void *b){
    int temp = *(int *)a;
    *(int *)a = *(int *)b;
    *(int *)b = temp;
}

int main(){
    int a = 10;
    int b = 15;
    swap(&a, &b);
    printf("a = %d \nb = %d",a ,b);

    return 0;
}