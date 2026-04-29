#include<iostream>
using namespace std;

int main()
{
    int n,sum=0;
    while(1) // this is use for infinite loop & we use 1 for true value
    {
        cout<<"enter a number of your choice: ";
    cin>>n;
       
    if(n<0){
        continue;// we use continue to ignore the number
    }
    if(n==0){
        break;//we use break to terminate the loop if condition is true
    }
     sum =sum+n;
}
    cout<<"sum of number is :"<<sum<<endl;
    return 0;
}