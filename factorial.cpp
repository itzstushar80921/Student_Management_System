#include<iostream>
using namespace std;

int main()
{
    int fact=1,i,n;
    cout<<"enter a number : ";
    cin>>n;

    for(i=1;i<=n;i++)
    {
    fact=fact*i;
    }

cout<<"factorial of number is :"<< n<<"!="<<fact<<endl;

return 0 ;
    }