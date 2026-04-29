#include<stdio.h>
int main()
{
    for(int i=1;i<=5;i++)//print row
    {
        for(int j=1;j<=i;j++)//print value in row
        {
            printf(" *");
        }
        printf("\n");
    }
   return 0; 
}