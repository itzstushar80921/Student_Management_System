#include<iostream>
using namespace std;

int main()
{
    int a,b,temp;
    cout<<"enter two number to find gcd or hcf: ";
    cin>>a>>b;
    while( b%a!=0)
    {  
        temp = b%a;
        b=a;
        a=temp;
        
    }
    cout<<"highest common factor:"<<a<<endl;
    return 0;
}