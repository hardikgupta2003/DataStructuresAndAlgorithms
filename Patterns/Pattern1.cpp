#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the size of pyramid : ";
    cin>>n;
   
    for (int i=0;i<n;i++){
        for(int j=0;j<2*n-i-2;j++){
            cout<<"* ";
        }
        for(int j=0;j<2*i+1;j++){
            if(j%2==1 ){
                cout<<"* ";
            }
            else{
                cout<<i+1<<" ";
            }
        }
        for(int j=0;j<2*n-i-2;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}