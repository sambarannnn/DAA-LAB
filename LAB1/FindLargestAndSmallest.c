/*
1.1Write a program to store random numbers into an array of n integers and
then find out the smallest and largest number stored in it.
n is the user input.
*/
#include <stdio.h>
#include <stdlib.h>
void input(int arr[], int n) {
    int lower = 0;
    int upper = 100;
    for(int i = 0; i < n; i++) {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }
}


void function(int *arr, int n, int *min, int *max) {
    printf("\nArray elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if(i == 0){
            *min = arr[i];
            *max = arr[i];
        } else {
            if(arr[i] < *min)
                *min = arr[i];
            if(arr[i] > *max)
                *max = arr[i];
        }
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter value of n : ");
    scanf("%d", &n);
    int arr[n];
    input(arr, n);

    int min, max;

    function(arr, n, &min, &max);

    printf("\nSmallest Element : %d\n", min);
    printf("Largest Element : %d\n", max);

    return 0;
}
