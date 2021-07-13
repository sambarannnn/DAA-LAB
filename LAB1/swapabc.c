/*
1.4Write a program that takes three variable (a, b, c) as separate parameters
and rotates the values stored so that value a goes to be, b, b to c and c to a
by using SWAP(x,y) function that swaps/exchanges the numbers x & y.
*/
#include <stdio.h>

void swap2(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap3(int *x, int *y, int *z) {
    *x = *x + *y + *z;

    //total - (og y + og z) to get og x at y
    *y = *x - (*y + *z);//has og x value now

    //total - (og x + og z) to get og y at z
    *z = *x - (*y + *z);

    //total - (og y + og z) to get og z at x
    *x = *x - (*z + *y);
}

int main()
{
    int a, b, c;
    printf("Enter a, b, c : ");
    scanf("%d%d%d", &a, &b, &c);

    printf("\nBefore Swapping : \n");
    printf("(a, b, c) -> (%d, %d, %d)\n\n", a, b, c);

    //a,b,c -> a,c,b -> c,a,b

    // swap2(&b, &c);
    // //now its a, c, b
    // swap2(&a, &b);
    //now its c, a , b

    //ALTER
    swap3(&a, &b, &c);
    printf("After Swapping : \n");
    printf("(a, b, c) -> (%d, %d, %d)\n", a, b, c);

    return 0;
}
