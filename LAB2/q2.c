#include <stdio.h>
#include <time.h>

int euclidean_gcd(int a, int b)
{
    if (a == 0)
        return b;
    return euclidean_gcd(b%a, a);
}

int consec_int_checking(int m, int n) {
    int t, r, g;
    if(m>n)
        t = n;
    else
        t = m;
    a:do {
        r = m % t;
        if(r != 0)
            t--;
    } while(r != 0);
    if(r == 0) {
        r = n % t;
        if(r == 0)
            g = t;
        else {
            t--;
            goto a;
        }
    }
    return g;
}
#define MAXFACTORS 1024
typedef struct{
   int size;
   int factor[MAXFACTORS + 1];
   int exponent[MAXFACTORS + 1];
} FACTORIZATION;
void FindFactorization(int x, FACTORIZATION* factorization){
   int i, j = 1;
   int n = x, c = 0;
   int k = 1;
   factorization->factor[0] = 1;
   factorization->exponent[0] = 1;aa
   for (i = 2; i <= n; i++) {
      c = 0;
      while (n % i == 0) {
         c++;
         n = n / i;
      }
      if (c > 0) {
         factorization->exponent[k] = c;
         factorization->factor[k] = i;
         k++;
      }
   }
   factorization->size = k - 1;
}

int gcdMiddleSchoolProcedure(int m, int n){
   FACTORIZATION mFactorization, nFactorization;
   int r, mi, ni, i, k, x = 1, j;
   FindFactorization(m, &mFactorization);
   FindFactorization(n, &nFactorization);
   int min;
   i = 1;
   j = 1;
   while (i <= mFactorization.size && j <= nFactorization.size) {
      if (mFactorization.factor[i] < nFactorization.factor[j])
         i++;
      else if (nFactorization.factor[j] < mFactorization.factor[i])
         j++;
      else{
         min = mFactorization.exponent[i] > nFactorization.exponent[j] ? nFactorization.exponent[j] : mFactorization.exponent[i];
         x = x * mFactorization.factor[i] * min;
         i++;
         j++;
      }
   }
   return x;
}

int main()
{
    int a, b;
    double time_spent = 0.0;
    printf("Enter first number : ");
    scanf("%d", &a);
    printf("Enter second number : ");
    scanf("%d", &b);

    clock_t begin = clock();
    printf("GCD(%d, %d) = %d\n", a, b, euclidean_gcd(a, b));
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f ms\n", time_spent*1000);

    begin = clock();
    printf("GCD(%d, %d) = %d\n", a, b, consec_int_checking(a, b));
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f ms\n", time_spent*1000);

    begin = clock();
    printf("GCD(%d, %d) = %d\n", a, b, gcdMiddleSchoolProcedure(a, b));
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f ms\n", time_spent*1000);

    return 0;
}
