#include <stdio.h>
#include <stdbool.h>//to use bool, true, false
#include <time.h>
#include <math.h>
#include <stdlib.h>
bool checkPrimality1(int n){
    if(n<=1){
        return false;
    }
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
bool checkPrimality2(int n){
    if(n==1) return false;
	int a = 2;
	while(a<n-1){
        int x = pow(a,n-1);
		if(x%n != 1){
			return false;
		}
		a++;
	}
	return true;
}

int powerhelper(int x, unsigned int y, int p){
	int res = 1;
	x = x % p;

	while (y > 0){
		if (y & 1)
			res = (res*x) % p;

		y = y/2;
		x = (x*x) % p;
	}
	return res;
}

bool miillerTest(int d, int n){

	int a = 2 + rand() % (n - 4);

	int x = powerhelper(a, d, n);

	if (x == 1 || x == n-1)
	return true;

	while(d != n-1){
		x = (x * x) % n;
		d *= 2;

		if (x == 1)	 return false;
		if (x == n-1) return true;
	}


	return false;
}

bool checkPrimality3(int n, int k){

	if(n <= 1 || n == 4) return false;
	if(n <= 3) return true;

	int d = n - 1;
	while(d % 2 == 0)
		d = d/2;

	for(int i = 0; i < k; i++)
		if(!miillerTest(d, n))
			return false;
	return true;
}

int main() {
    double time_spent = 0.0;
    int n;
    printf("Enter number : ");
    scanf("%d", &n);
    printf("\nALGO-1 : \n");
    clock_t begin = clock();
    if(checkPrimality1(n))
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f ms\n", time_spent*1000);

    printf("\nALGO-2 : \n");
    begin = clock();
    if(checkPrimality2(n))
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);

    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f ms\n", time_spent*1000);

    printf("\nALGO-3 : \n");
    begin = clock();
    if(checkPrimality3(n, 4))//4 iterations
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);

    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f ms\n", time_spent*1000);


}
