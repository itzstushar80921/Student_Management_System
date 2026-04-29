#include<stdio.h>
int main()
{
    int a =10;
    int *p;
    p=&a;
    printf("value of a  :%d\n",a);
     printf("address of a  :%d\n",&a);
      printf("pointer p stores =  :%d\n",p);
       printf("value at *p = :%d\n",*p);
}