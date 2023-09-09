#include <iostream>
using namespace std;

void Sort01(int arr[],int n){
    int zeroCount=0;
    int oneCount=0;
    int index=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            zeroCount++;
        }
        else{
            oneCount++;
        }
    }

    while(zeroCount--){
        arr[index]=0;
        index++;
    }
     while(oneCount--){
        arr[index]=1;
        index++;
     }
     cout<<"sorted array : ";
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }

}

int main(){
   int arr[]={0,1,1,0,1,0,1};
   int n=7;

   Sort01(arr,n);

    return 0;
}