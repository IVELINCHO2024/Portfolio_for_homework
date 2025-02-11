#include <stdio.h>
#define DEBUG

int main(){
    int arr[]={1,3,5,2,554,23,5,6};
    int size = sizeof(arr)/sizeof(arr[0]); 
    #ifdef DEBUG
    do{
        for(int i=0; i<size-1;i++){
            for(int j=i+1;j<size;j++){
                int c=arr[i];
                arr[i]=arr[j];
                arr[j]=c;
            }
        }
    }while(0);

    for(int k=0;k<size;k++){
        printf("%d",arr[k]);
    }
    printf("\n");
    int sum=0;

    for(int z=1;z<size;z++){
        if(z%3==0){
            sum=sum+arr[z];
        }
    }

    printf("%d",sum);
    #endif



    return 0;
}