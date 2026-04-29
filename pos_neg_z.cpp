#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number:";
    cin>>n;
    if (n>0)
    {
        cout<<"entered number is positive"<<endl;
    
    }
    else if (n<0)
    {
        cout<<" entered number is negative\n";// \n is use at a place of endl also known as esacape sequence

    }
    else{
        cout<<"entered number is equal to zero"<<endl;
        return 0;
    }


}