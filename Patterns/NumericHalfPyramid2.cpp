#include <iostream>
using namespace std;

int main(){
    int m;
    cout<<"enter the size of pyramid : ";
    cin>>m;
   
    for (int i=1;i<=m;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}