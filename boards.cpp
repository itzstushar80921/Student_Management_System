#include<iostream>
using namespace std;

int main() {
    int phy ,chem,maths;

    cout<< "enter your physics marks:";
    cin >> phy;//way to input in c++

    cout<< "enter your chemistry marks:";
    cin >> chem;

    cout<<"enter your maths marks:";
    cin>> maths;

    if(phy>=33 && chem>=33 && maths>=33){
    cout<<"you have passed"<<endl;
    //return 0;here program will stop if put this

    float percent =(phy+chem+maths)/3.0;//phy ;chem; maths are in int that why we use 3.0 instead of 3 called type casting
    
    if (percent >=75){
    cout << "you are qualified for admission in iit and nit"<< endl;
    }
    else{
        cout<< "you are not qualified"<<endl;
    }
    }
    else{
    cout<< "failed" << endl;
    }
}