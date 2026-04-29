#include<stdio.h>
int main()
{
    int num,rev=0,dig,m;
    printf("enter a number :");
    scanf("%d" ,&num);
    m=num;
    while(num!=0)
    {
     dig= num % 10;
     rev= rev*10+ dig;// use to reverse the number
     num=num/10;
   }
    if (m == rev)
    {
        printf("yes it is palindromic number ");
    }
    else
    {
     printf("no it is not a palindromic number");
    }
}