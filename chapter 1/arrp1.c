#include<stdio.h>
int main()
{
    int i, f=0,k,pos=0;
    int arr[5];
    printf("enter 5 integer in array:\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",& arr[i]);
    }
    printf("enter a number want to search");
    scanf("%d",k);
    for(i=0;i<5;i++)
    {
        if(k==arr[i])
        f==1;
        pos=i;
        break;
    }
    if (f==1)
    {
    printf("search is successful %d",pos);
    }
    else
    {
        printf("search is unsuccessful element not found");
    }
}