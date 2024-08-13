#include<iostream>
using namespace std;


int maxCut(int n,int x,int y,int z){
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT8_MIN;
    }
   
    int op1=1+maxCut(n-x,x,y,z);
    int op2=1+maxCut(n-y,x,y,z);
    int op3=1+maxCut(n-z,x,y,z);
    int finalans=max(op1,max(op2,op3));
    return finalans;
}

int main()
{
    int n=4;
    int x=2;
    int y=1;
    int z=1;
    int res=maxCut(n,x,y,z);
    cout<<"final ans : "<<res;

}