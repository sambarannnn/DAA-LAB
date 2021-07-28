/*
1.2Write a program to store random numbers into an array of n integers,
where the array must contains some duplicates. Do the following:
a)Find out the total number of duplicate elements.
b)Find out the most repeating element in the array.
*/

#include <stdio.h>
#include <stdlib.h>
void BubbleSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void function(int *arr, int n) {
    //arr is sorted first
    BubbleSort(arr, n);

    int total_duplicates = 0;
    int curr_repeating = 1;
    int max_repeating = 1;
    int most_repeating;
    for(int i = 0; i < n-1; i++) {
        if(arr[i] == arr[i+1]) {
            curr_repeating++;
            total_duplicates++;//will consider 1st occurence of a duplicate ele as unique
        } else {
            curr_repeating = 1;
        }
        if(curr_repeating > max_repeating) {
            max_repeating = curr_repeating;
            most_repeating = arr[i];
        }
    }
    printf("Total Number of duplicate elements : %d\n", total_duplicates);
    printf("Most repeating element : %d\n", most_repeating);
}

void input(int arr[], int n) {
    int lower = 0;
    int upper = n/2;
    for(int i = 0; i < n; i++) {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }
}

void printArray(int arr[], int n) {
    printf("\nArray Elements: ");
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
    printArray(arr, n);
    function(arr, n);
    return 0;
}
