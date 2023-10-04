#include <iostream>
using namespace std;

int main(){


    int a=10;
    cout<<a<<endl;
    cout<< "address of a : "<<&a<<endl;

    //pointer creation
    int * ptr=&a;
    cout<<"accessing : "<<*ptr<<endl;
    cout<<"address of ptr : "<<&ptr<<endl;
    cout<<ptr<<endl;



    return 0;
}