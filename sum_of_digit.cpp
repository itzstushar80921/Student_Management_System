#include<iostream>
using namespace std;

int main() {

    int num, sum=0,product = 1;

    cout<<"enter a number: ";
    cin>> num;

    while(num!=0)
     {
     int digit = num % 10;//remainder ko as answer karne ke liye
    sum =sum + digit;// remainder ko sum karne ke liye
    product =product*digit;//product of digit ke liye
    num =num/10;//quotient ko number mein input lene ke liye
    }
    cout<<" sum of your input digits is : " << sum<<endl;
    cout<<"product of a digit is "<<product;

    return 0;
}