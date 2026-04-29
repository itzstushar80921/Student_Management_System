#include<stdio.h>
int main()
{
    int row;
    printf("enter number of row to be print : ");
    scanf("%d",&row);
    for(int i=1;i<=row;i++)
    {
        for(int space=i;space<row;space++)//for print space 
        {
            printf(" ");
        }
        for(int j=1;j<= (2*i-1);j++)
            { 
             printf("*");
             }
             printf("\n");
    }

}