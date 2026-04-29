#include <iostream>
using namespace std;

int main() {
    int max=0,num;

    cout<<"enter the positive number, to end enter 0 or a negative number:"<<endl;
    cin>>num;
    while (num > 0)
    {
      if(num>max){
        max = num;
      }  
      cin>> num;
    }
    cout <<"maximum number from your input is "<<max;
    
}