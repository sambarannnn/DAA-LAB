/*
1.6Write a program to find out the second smallest and second largest element stored in an
array of n integers. n is the user input. The array takes input through random number
generation within a given range. How many different ways you can solve this problem.
Write your approaches & strategy for solving this problem.
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

void function(int *arr, int n, int *sec_min, int *sec_max) {
    //Alternate but slower method would be to sort the array and pick second most boundary values
    int min;
    int max;
    printf("\nArray elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if(i == 0){
            min = arr[i];
            max = arr[i];
        } else {
            if(arr[i] < min) {
                *sec_min = min;//tails the min
                min = arr[i];
            }
            if(arr[i] > max) {
                *sec_max = max;//tails the max
                max = arr[i];
            }

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

    int sec_min, sec_max;

    function(arr, n, &sec_min, &sec_max);

    printf("\nSecond Smallest Element : %d\n", sec_min);
    printf("Second Largest Element : %d\n", sec_max);

    return 0;
}
