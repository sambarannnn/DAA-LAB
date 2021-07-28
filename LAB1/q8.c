#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void product_array_convert(int* ptr1, int* ptr2, int n){
    int i,j;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                *(ptr2+i) = *(ptr2+i) * *(ptr1+j);
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int input_arr[n], output_arr[n];
    srand(time(0));
    for(int i=0;i<n;i++) input_arr[i] = 1 + rand()%5;

    for(int i=0;i<n;i++) output_arr[i] = 1;

    printf("\nThe input array is:");
    for(int i=0;i<n;i++){
        printf(" %d",input_arr[i]);
    }

    product_array_convert(&input_arr[0],&output_arr[0],n);

    printf("\nThe output array is:");
    for(int i=0;i<n;i++){
        printf(" %d",output_arr[i]);
    }
    printf("\n");
    return 0;
}
