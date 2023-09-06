#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the size of pyramid : ";
    cin>>n;
   
    for (int i=0;i<n;i++){
        for(int j=0;j<i;j++){
           if(i==0 || i==n-1){
               cout<<j+1<<" ";
           
            }
           else{

            if(j==0 || j==n-i ){
            cout<<j+1<<" ";
           }
           else{
             cout<<"  ";
           }
            
           }
        }
        cout<<endl;
    }
    return 0;
}