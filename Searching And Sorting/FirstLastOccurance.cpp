#include<iostream>
using namespace std;

int firstOccurance(int arr[],int n,int target){
    int start=0;
    int end=n-1;
    int index=-1;
    int mid=(start+end)/2;
    while(start<=end){
        if(arr[mid]==target){
            index=mid;
            end=mid-1;
        }
        else if(arr[mid]>target){
            end=mid-1;

        }
        else{
            start=mid+1;
        }

    mid=(start+end)/2;
    }
    return index;
    
}

int lastOccurance(int arr[],int n,int target){
    int start=0;
    int end=n-1;
    int index=-1;
    int mid=(start+end)/2;
    while(start<=end){
        if(arr[mid]==target){
            index=mid;
            start=mid+1;
        }
        else if(arr[mid]>target){
            end=mid-1;

        }
        else{
            start=mid+1;
        }

    mid=(start+end)/2;
    }
    return index;
    
}

int main(){

    int arr[]={10,30,30,30,30,30,50,};
    int n=7;
    int firstOcc = firstOccurance(arr,n,30);
    int lastOcc = lastOccurance(arr,n,30);
    int totalOccurance=lastOcc-firstOcc+1;
    cout<<"total occurance  : "<<totalOccurance<<endl;
    return 0;
}