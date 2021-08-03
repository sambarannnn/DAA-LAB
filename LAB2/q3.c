#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void input(int arr[], int n){
    for(int i=0; i<n; i++){
        arr[i]=1+rand()%100;
    }
}
void InsertionSortAsc(int arr[], int n){ int i, j, key;
    for (i=1; i<n; i++){
        key=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>key){ arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void InsertionSortDesc(int arr[], int n){ int i, j, key;
    for (i=1; i<n; i++){
        key=arr[i];
        j=i-1;
        while (j>=0 && arr[j]<key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void display(int arr[], int n){
    for (int i=0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int main(){
    int n, option=0, arr[50000]; time_t strt, end;
    double t;
    do {
        printf("**MAIN MENU**\n"); printf("0. Quit\n");
        printf("1. Input n random numbers into array\n"); printf("2. Display array\n");
        printf("3. Sort array in ascending order\n"); printf("4. Sort array in descending order\n");
        printf("5. Time complexity to sort random data in ascending order\n");
        printf("6. Time complexity to sort data in ascending order which is already sorted in ascending order\n");
        printf("7. Time complexity to sort data in ascending order which is already sorted in descending order\n");
        printf("Enter your choice: \n"); scanf("%d", &option);
        switch (option){
            case 1:
                printf("Enter n\n"); scanf("%d", &n);
                input(arr, n);
                break;

            case 2:
                display(arr, n);
                break;

            case 3:
                InsertionSortAsc(arr, n);
                printf("Array sorted in ascending order \n");
                break;

            case 4:
                InsertionSortDesc(arr, n);
                printf("Array sorted in descending order \n"); break;

            case 5:
                strt=clock(); InsertionSortAsc(arr, n); end=clock();
                t=end-strt;
                printf("Time complexity to sort random data: %f\n", t/CLOCKS_PER_SEC); break;

            case 6:
                InsertionSortAsc(arr, n); strt=clock(); InsertionSortAsc(arr, n); end=clock();
                t=end-strt;
                printf("Time complexity to sort random data: %f\n", t/CLOCKS_PER_SEC); break;

            case 7:
                InsertionSortDesc(arr, n); strt=clock(); InsertionSortAsc(arr, n); end=clock();
                t=end-strt;
                printf("Time complexity to sort random data: %f\n", t/CLOCKS_PER_SEC); break;
            }
        } while(option!=0);
}
