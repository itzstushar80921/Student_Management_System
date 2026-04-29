#include<stdio.h>
int main()
{
    int n,i,j,search;
    int found = - 1;
    scanf("%d",&n);
    int data[n];
    printf("enter %d numbers :\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d ",& data[i]);
    }
   /* printf("original array : [");
    for(i=0;i<n;i++)
    {
        printf("%d ",data[i]);
    }
    printf("]\n");*/
    printf(" enter a number to be search :  ");
    scanf("%d ",&search);
    for(i=0;i<n;i++)
    {
        if (data[i]==search);
        {
            found = i;
            break;
        }
    }
    if(found!=-1)
    {
        printf("\nsearch result :found value %d at index %d\n",search,found);
    }
    else{
        printf("\n search result : value %d not found\n",search);
    }
}