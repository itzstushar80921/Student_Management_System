#include<stdio.h>
int main()
{
    int p=0;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=i;j++)
        {
            p=p+1;
            printf("%d",p );

    }
    printf("\n");
}
   return 0; 
}