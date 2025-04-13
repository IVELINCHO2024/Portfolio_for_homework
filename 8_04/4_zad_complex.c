#include <stdio.h>


union even_odd{ 
    long odd;
    short even;
};


int main(){
    union even_odd num[10];
    for(int i = 0; i<=10; i++){
     if(i%2 == 0){
        num[i].even = i;
     }
     else{
        num[i].odd = i;
      }
    }

    for(int i = 0; i<10; i++){
        if(i%2 == 1){
            printf("odd: %ld\n", num[i].odd);
        }
        else{
            printf("even: %hd\n", num[i].even);
        }
    }
    

    return 0;
}