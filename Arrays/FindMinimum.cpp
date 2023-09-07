#include <iostream>
using namespace std;

int findMin(int n,int arr[],int min){
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
     return min;
}
int main (){
    int arr[6]={12,45,56,3,90,-9};
    int min=INT8_MAX;
    int foundMIN=findMin(6,arr,min);
     cout<<"Minimum value in this array : "<<foundMIN;

    return 0;
}