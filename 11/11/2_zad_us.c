#include <stdio.h>

#define ARRAY_SIZE 8
int main() {
    int array[ARRAY_SIZE];
    #if defined ARRAY_SIZE && ARRAY_SIZE > 0 && ARRAY_SIZE < 11
    int multi=1;
        for (int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = multi;
            multi=multi*2;
        }
        
        for (int j = 0; j < ARRAY_SIZE; j++) {
            printf("%d\n", array[j]);
        }
    #else
        #error
    #endif
    
    return 0;
}
