#include<iostream>
using namespace std;

int main(){
    int Sum= 0 ,n;
    int i=1;
    cout<<"enter a number:";

    cin>>n;

    while(i<=n){
    Sum=Sum+i;
    i=i+1;
    //cout<< sum <<endl;
    }

    cout<< Sum ;
}