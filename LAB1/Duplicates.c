#include <stdio.h>
#include <stdio.h>

void input(int arr[], int n) {
    printf("Enter elements : ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

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

void function(int arr[], int n) {
    int total_duplicates = 0;
    int curr_repeating = 1;
    int max_repeating = 1;
    int most_repeating;
    for(int i = 0; i < n-1; i++) {
        if(arr[i] == arr[i+1]) {
            curr_repeating++;
            // total_duplicates++;//will consider 1st occurence of duplicate ele as unique
        } else {
            if(curr_repeating != 1)
                total_duplicates += curr_repeating;//will consider every occurence of duplicate elements
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

int main()
{
    int n;
    printf("Enter value of n : ");
    scanf("%d", &n);
    int arr[n];

    input(arr, n);
    BubbleSort(arr, n);

    function(arr, n);
    return 0;
}
