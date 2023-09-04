#include <iostream>
using namespace std;

int main(){
    int m;
    cout<<"enter the size of square : ";
    cin>>m;
   
    for (int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    return 0;
}