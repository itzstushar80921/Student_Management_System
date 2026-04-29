#include<iostream>
using namespace std;

int main()
{
    int i,n,flag=1; //flag variable use karke hum true or flase answer kar sakte hai
    cout<<"enter a number: ";
    cin>>n;
    for(i=2;i < n;i++){
        if(n % i == 0){
        cout<<"number is not a prime"<<endl;
        flag = 0;
        break;
        }
            
    }
    if (flag)
    {
        cout<<"number is prime"<<endl;
    }
}