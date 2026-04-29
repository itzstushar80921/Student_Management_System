#include <iostream>
using namespace std;

int main() {
  char ch;
  cin>>ch;
  if (ch>='0'&& ch <='9')  {
    cout<<"numeric value\n";
  }
  else if (ch>='a' && ch<='z'){
  cout <<"lowercase\n";
  }
  else if (ch>='A'&& ch<='Z'){
    cout<<"upercase\n";
  }
  else{
    cout<<"special character\n";
  }
}