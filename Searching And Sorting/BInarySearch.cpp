#include<iostream>
using namespace std;

int BinarySearch(int arr[],int n,int target){
    int start=0;
    int end=n-1;
    int mid=(start+end)/2;
    while(start<=end){
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            end=mid-1;

        }
        else{
            start=mid+1;
        }

    mid=(start+end)/2;
    }
    return -1;
}

int main(){

    int arr[]={10,20,30,40,50,60,70,80,90};
    int n=9;
    int index = BinarySearch(arr,n,70);
    cout<<"element found at : "<<index<<endl;
    return 0;
}