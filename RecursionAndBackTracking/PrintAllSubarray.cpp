#include <bits/stdc++.h>
using namespace std;

void printSA(int arr[],int n,int s,int e){

    if(e >= n){
        return ;
    }

    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    printSA(arr,n,s,e+1);
    
}
void printTill(int arr[],int n){
    for(int i=0;i<n;i++){
        int end=i;
        printSA(arr,n,i,end);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        }
    int s=0;
    int e=s;
    printTill(arr,n);

    return 0;
}