#include <iostream>
using namespace std;

 
int Sum(int row ,int col,int arr[][3] ){
    int sum=0;
    for(int i=0;i<row;i++){
            sum=sum+arr[i][i];
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
   
    cout<<"Sum of 2D array : "<<Sum(row,col,arr);
    return 0;
}