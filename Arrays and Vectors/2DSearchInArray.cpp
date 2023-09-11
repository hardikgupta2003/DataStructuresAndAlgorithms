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
bool search(int row ,int col,int arr[][3] ,int target){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==target){
                return true;
            }
            
            
        }
       
    }
    return false;
}

int main(){
    
    int arr[][3]={
        {13,24,36},
        {51,62,83},
        {11,92,73}
    };


    int target=366;
    int row=3;
    int col=3;
   
    cout<<"Found it or not : "<<search(row,col,arr,target);
    return 0;
}