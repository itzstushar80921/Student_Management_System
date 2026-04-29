#include<iostream>
using namespace std;

int main()
{
    int dig,rev =0,num;
    cout << "enter your number to revrese: ";
    cin>> num;
    while(num!=0)
   { 
    dig= num%10;
    rev= rev*10+dig;// use to reverse the number
    num=num/10;
   }
   cout<<"number after reverse :"<<rev;
   return 0;

    
} 
