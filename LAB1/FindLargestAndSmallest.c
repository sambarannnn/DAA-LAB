/*
1.1Write a program to store random numbers into an array of n integers and
then find out the smallest and largest number stored in it.
n is the user input.
*/#include <stdio.h>

void input(int arr[], int n) {
    printf("Enter elements : ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void function(int arr[], int n, int *min, int *max) {
    for(int i = 0; i < n; i++) {
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

    printf("Smallest Element : %d\n", min);
    printf("Largest Element : %d\n", max);

    return 0;
}
