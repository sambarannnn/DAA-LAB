#include<stdio.h>
#include<stdlib.h>

int main()
{
int choice, num1,num2,r,min,i,c,ans=1,m,n,count;

printf("Press 1 for Euclid's Algorithm'\n");
printf("Press 2 for Consecutive integer checking Algorithm.\n");
printf("Press 3 for Middle school procedure which makes use of common prime factors.\n"); printf("Enter your choice:\n");
scanf("%d",&choice); switch (choice) {
case 1: {
printf("Enter-two integer numbers: "); count++;
scanf ("%d %d", &num1, &num2); count++;
while (num2 > 0) {
r = num1 % num2; num1= num2; num2 = r;
}
count++;
printf("GCD = %d \n",num1); count++;
printf("The Count is %d\n",count);
break;

}
case 2:{

printf("Enter-two integer numbers: "); count++;
scanf ("%d %d", &num1, &num2); count++;
if(num1<num2) min=num1;
else
min=num2; count++; r=min; count++;
while (r>0){
if(num1 % r == 0 && num2 % r == 0) return r;
count++; r=r - 1; count++;
printf ("GCD = %d \n",r); count++;
printf("The Count is %d\n",count);

}
break;
}
case 3:{
printf("Enter-two integer numbers: "); count++;
scanf ("%d %d", &num1, &num2); count++;
c=num1>=num2?num2:num1; count++;
for(i=2;i<=c;i++){ m=0;
n=0;
if(num1%i==0){
m=1;
num1=num1/i;
}
count++; if(num2%i==0){

n=1;
num2=num2/i;
}
count++;
if(n==1 && m==1){
ans=ans*i;
}
count++; if(n==1 || m==1) i--;

}
count++;
printf ("GCD = %d \n",ans); count++;
printf("The Count is %d\n",count);

break;
}
default:
printf("wrong Input\n");

}
}
