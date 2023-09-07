#include <iostream>
using namespace std;

int count01(int n,int arr[]){

    int zeroCount=0;
    int oneCount=0;
    
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            zeroCount++;
        }
        else{
            oneCount++;
        }
    }
    cout<<"zero count : "<<zeroCount<<endl;
    cout<<"one count : "<<oneCount<<endl;
}
int main(){
    int arr[8]={1,0,0,1,1,1,0,1};
    count01(8,arr);
    return 0;
}