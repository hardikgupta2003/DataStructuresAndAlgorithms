#include <iostream>
using namespace std;

int main(){
    int m;
    cout<<"enter the size of pyramid : ";
    cin>>m;
   int count=1;
    for (int i=0;i<m;i++){
        for(int j=0;j<i+1;j++){
            cout<<count++<<" ";
        }
        cout<<endl;
    }
    return 0;
}