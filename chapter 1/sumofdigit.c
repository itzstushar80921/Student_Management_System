#include<stdio.h>
int main()
{
    int num,sum=0;
    printf("enter a number: ");
    scanf("%d",&num);
    while(num!=0)
     { //dig=num %10;
        //sum=sum+dig;
    sum += num % 10;//remainder ko as answer karne ke liye , remainder ko sum karne ke liye 
       num =num/10;//quotient ko number mein input lene ke liye
    }
    printf("sum of digit is %d",sum);
}