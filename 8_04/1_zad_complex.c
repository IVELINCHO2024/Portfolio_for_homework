#include <stdio.h>
typedef unsigned long long ull;
typedef ull (*func)(ull, ull);

ull add(ull a, ull b){
    return a + b;
}

ull reduce(ull arr[], ull size, func add, ull start){
    ull result = start;
    for (ull i = 0; i < size; i++){
        result = add(result, arr[i]);
    }
    return result;
}
int main(){
    printf("how many elements do you want to add: \n");
    ull size;
    scanf("%llu", &size);
    ull arr[size];
    for(int i = 0; i < size; i++){
        scanf("%llu", &arr[i]);
    }
    ull result = reduce(arr, size, add, 0);

    printf("Result: %llu", result);
    return 0;
}