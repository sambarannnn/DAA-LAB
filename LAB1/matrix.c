/*
1.5Let A be n*n square matrix array.
WAP by using appropriate user defined functions for the following:
a)Find the number of nonzero elements in A
b)Find the sum of the elements above the leading diagonal.
c)Display the elements below the minor diagonal.
d)Find the product of the diagonal elements.
*/

#include <stdio.h>
#include <stdlib.h>

void input(int **matrix, int n) {
    printf("Enter elements of %dx%d matrix : \n", n, n);
    for(int i = 0; i < n; i++) {
        matrix[i] = malloc(sizeof(int*) * n);
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printmatrix(int **matrix, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void function(int **matrix, int n) {
    int non_zero_elements = 0;
    int sum_above_leading_diagonal = 0;
    int diag_product = 1;

    printf("\n\nc. Printing elements below minor diagonal : \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            //a
            if(matrix[i][j] != 0)
                non_zero_elements++;

            //b
            if(j > i)
                sum_above_leading_diagonal += matrix[i][j];

            //c
            //main diag & secondary diag
            if(i == j || (i + j) == (n-1))
                diag_product *= matrix[i][j];

            if((i + j) >= n)
                printf("%d ", matrix[i][j]);
            else
                printf("_ ");

        }
        printf("\n");
    }
    //mid element is multiplied twice if n is odd(odd no of rows)
    if(n%2 == 0) {
        int mid = n/2;
        diag_product /= matrix[mid][mid];
    }

    printf("\na. No. of non-zero elements : %d.", non_zero_elements);
    printf("\nb. Sum of the elements above the leading diagonal : %d.", sum_above_leading_diagonal);
    printf("\nd. Product of the diagonal elements : %d.", diag_product);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter value of n : ");
    scanf("%d", &n);
    int **matrix = malloc(sizeof(int**) * n);
    input(matrix, n);
    //printmatrix(matrix, n);

    function(matrix, n);

}
