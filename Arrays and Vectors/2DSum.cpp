#include <iostream>
using namespace std;

 
int search(int row ,int col,int arr[][3] ){
    int sum=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            sum=sum+arr[i][j];
            
            
        }
       
    }
    return sum;
}

int main(){
    
    int arr[][3]={
        {13,24,36},
        {51,62,83},
        {11,92,73}
    };


    
    int row=3;
    int col=3;
   
    cout<<"Sum of 2D array : "<<search(row,col,arr);
    return 0;
}

// we can print column wise sum by replacing i with j and j with i..in arr[i][j]