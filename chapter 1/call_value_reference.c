#include<stdio.h>
void call_value(int x){ x=x+10;}
void call_reference(int *x){*x=*x+10;}
int main()
{
    int a=10,b=10;
    call_value(a);
    printf("value %d \n:",a);
    call_reference(&b);
    printf("reference : %d ",b);
    return 0;
}