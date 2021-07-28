#include<stdio.h>
#include <stdlib.h>
#include<time.h>

void swap(int *x,int *y){
   int temp;
   temp=*x;
   *x=*y;
   *y=temp;
}

int main(){
   int n;
   printf("Enter the value of n: ");
   scanf("%d",&n);
   int arr[n];
   srand(time(0));
   for(int i=0;i<n;i++) arr[i] = 1 + rand()%20;

   printf("\nThe array is:");
   for(int i=0;i<n;i++){
       printf(" %d",arr[i]);
   }

   if(n%2==0){
       for(int i=0;i<n;i=i+2){
           swap(&arr[i], &arr[i+1]);
       }
   }
   else{
       for(int i=0;i<n-1;i=i+2){
           swap(&arr[i], &arr[i+1]);
       }
   }
   printf("\n\nThe array after swapping is:");
   for(int i=0;i<n;i++){
       printf(" %d",arr[i]);
   }
   printf("\n");
}
