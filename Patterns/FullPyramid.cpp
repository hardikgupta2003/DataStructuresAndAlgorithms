#include <iostream>
using namespace std;

int main(){
    int m;
    cout<<"enter the size of pyramid : ";
    cin>>m;
   
    for(int i=0;i<m;i++){

        for(int j=0;j<m-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            cout<<"* ";
        }
       cout<<endl;


    }

    return 0;
}