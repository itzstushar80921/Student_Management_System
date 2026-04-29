#include<stdio.h>
int main()
{
int a,b,c;
printf("enter a number : ");
scanf("%d %d %d",&a,&b,&c);
if (a>=b && a>=c)
printf("%d is greatest ",a);
if (b>=a && b>=c)
printf("%d is greatest ",b);
if (c>=a && c>=b)
printf("%d is greatest ",c);
return 0;
}