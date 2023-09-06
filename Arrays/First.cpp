#include <iostream>
using namespace std;

// array creation
int main(){
    int arr[5]={3,4,5,0,1};
    bool brr[2]={1,0};

    cout<<addressof(arr)<<endl;
    cout<<sizeof(arr)<<endl;

    cout<<arr[4]<<endl;

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}