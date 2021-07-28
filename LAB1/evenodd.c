/*
1.3Write a program to rearrange the elements of an array of n integers
such that all even numbers are followed by all odd numbers.
How many different ways you can solve this problem.
Write your approaches & strategy for solving this problem.
*/
#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void function(int *arr, int n) {
    //we can use auxilliary Array : extra space, one iteration
    //or we can use two pointer method : one iteration, no extra space

    //using left to populate evens
    //using right to populate odds
    int left = 0;
    int right = n-1;
    while(left < right) {
        while(arr[left] % 2 == 0)
            left++;
        while(arr[right] % 2 != 0)
            right--;
        //now swap
        swap(&arr[left], &arr[right]);
        left++;
        right--;
    }
}

void input(int arr[], int n) {
    printf("Enter elements : ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}
void printArray(int *arr, int n) {
    printf("Array elements : \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
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

    function(arr, n);

    printArray(arr, n);
    return 0;
}
