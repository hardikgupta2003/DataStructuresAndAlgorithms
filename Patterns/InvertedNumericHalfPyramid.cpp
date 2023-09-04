#include <iostream>
using namespace std;

int main(){
    int m;
    cout<<"enter the size of pyramid : ";
    cin>>m;
   
    for (int i=1;i<=m+1;i++){
        for(int j=1;j<=m-i+1;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}