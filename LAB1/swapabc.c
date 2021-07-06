/*
1.4Write a program that takes three variable (a, b, c) as separate parameters
and rotates the values stored so that value a goes to be, b, b to c and c to a
by using SWAP(x,y) function that swaps/exchanges the numbers x & y.
*/
#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a, b, c;
    printf("Enter a, b, c : ");
    scanf("%d%d%d", &a, &b, &c);

    printf("\nBefore Swapping : \n");
    printf("(a, b, c) -> (%d, %d, %d)\n\n", a, b, c);

    //a,b,c -> a,c,b -> c,a,b

    swap(&b, &c);
    //now its a, c, b
    swap(&a, &b);
    //now its c, a , b

    printf("After Swapping : \n");
    printf("(a, b, c) -> (%d, %d, %d)\n", a, b, c);

    return 0;
}
