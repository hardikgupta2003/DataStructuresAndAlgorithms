#include <iostream>
using namespace std;

void ReverseArray(int n ,int arr[]){
    int start=0;
    int end=n-1;

    while (start<end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
}

int main(){
    int arr[5]={10,20,30,40,50};
    ReverseArray(5,arr);
    return 0;

}