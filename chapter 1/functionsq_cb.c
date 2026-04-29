#include<stdio.h>
int sq(int x) {return x*x;}
int cb(int x) {return x*x*x;}
int main()
{
    int n;
    printf("enter a number :  ");
    scanf("%d",&n);
    printf("sq: %d,cube: %d",sq(n),cb(n));
    return 0;
}