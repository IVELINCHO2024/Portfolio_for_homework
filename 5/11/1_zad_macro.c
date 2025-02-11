#include <stdio.h>
#define SIZE 5
#define MAKRO \
int arr[SIZE]={1,2,3,4,5}; \
 for(int i=0;i<5;i++){ \
     printf("%d ",arr[i]); \
 }



int main() {
  
  MAKRO


    return 0;
}