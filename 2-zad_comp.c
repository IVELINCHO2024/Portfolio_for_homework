
#include <stdio.h>

int main() {
   int a=12, b=128;
   int i=a;
   
   while(1){
       if(i%b==0)break;
       else{
           i=i+a;
       }
       
   }
   printf("НОК на тези две числа е:%d",i);
   
    return 0;
}