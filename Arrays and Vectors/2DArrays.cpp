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
void printArray(int row ,int col,int arr[][3]){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    
    // int arr[][3]={
    //     {1,2,3},
    //     {1,2,3},
    //     {1,2,3}
    // };

    int brr[3][3];
    
    int row=3;
    int col=3;
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>brr[i][j];
        }
        cout<<endl;
    }
    printArray(row,col,brr);
    return 0;
}