#include <iostream>
using namespace std;

//column wise
// void printArray(int row ,int col,int arr[][3]){
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//             cout<<arr[j][i]<<" ";
//         }
//         cout<<endl;
//     }
// }

// row wise 
int Max(int row ,int col,int arr[][3] ,int max){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]>max){
                max=arr[i][j];
            }
            
            
        }
       
    }
   return max;
}
int Min(int row ,int col,int arr[][3] ,int min){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]<min){
                min=arr[i][j];
            }
            
            
        }
       
    }
   return min;
}

int main(){
    
    int arr[][3]={
        {13,24,36},
        {51,62,83},
        {11,92,160}
    };


    int max=INT8_MIN;
    int row=3;
    int col=3;
   int min=INT32_MAX;
    cout<<"Maximum : "<<Max(row,col,arr,max);
    cout<<" Minimum : "<<Min(row,col,arr,min);
    return 0;
}