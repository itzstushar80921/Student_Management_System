#include<iostream>
using namespace std;

int main ()
{
    float i,term=1.0,sum=0.0,x;
    int num;
    cout<<"enter a number :";
    cin>>x>> num;
    for(i=1;i<=num;i++){

        sum= sum + term;
        term=term * x / i;
      }
      cout<< "e^x "<<x<<" = "<< sum<<endl;
    
}