#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lines_removing(char *arr){
    char *result = strchr(arr, '\n');
    if(result){

        *result = '\0';
    } 
}

int main(){

    return 0;
}