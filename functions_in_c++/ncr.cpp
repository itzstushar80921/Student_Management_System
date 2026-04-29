#include<iostream>
using namespace std ;

factorial(int n){
    int i=1,f=1;

    while(i<=n){
        f*=i;
        i++;
    }
    return f; 
}
int nCr(int n ,int r){
 return factorial(n)/(factorial(r)*factorial(n-r));   
}
int main()
{
    
    cout<<"5_c_4 ="<<nCr(5,4)<<endl;
}
