#include <stdio.h>
int main(){
    int num,sum=0;
    printf ("Enter a number");
    scanf("%d",&num);
    while(num!=0){
        int digit = num%10;
        sum += digit;
        num/=10;
        }
        printf ("%d",sum);
        return 0;
}