#include <iostream>
using namespace std;

 
void Transpose(int row ,int col,int arr[][3] ){
   
    for(int i=0;i<row;i++){
        for(int j=i;j<row;j++){
            swap(arr[i][j],arr[j][i]);
        }
         
    }
  
}

void printArray(int row ,int col,int arr[][3]){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    
    int arr[][3]={
        {2,4,6},
        {8,3,5},
        {7,9,1}
    };


    
    int row=3;
    int col=3;
   
    cout<<"Transpose of 2D array : "<<endl;
     Transpose(row,col,arr);
    printArray(row,col,arr);
    return 0;
}