/*#include<stdio.h>
int main()
{
    int a= 5;//by assigning value
    int b= 10;
    int sum = a+b;
    printf("sum: %d ",sum);
}*/
#include<stdio.h>
int main()
{
    int a,b;//declaration of a variable
    printf("enter the two numbers for sum");
    scanf("%d %d",&a,&b);
    int sum = a+b;
    printf("sum of two numbers is: %d",sum);
}