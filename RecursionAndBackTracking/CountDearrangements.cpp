#include <iostream>
using namespace std;

int solve(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    int ans= (n-1)*(solve(n-1)+solve(n-2));
    return ans;
}

int main(){
    int n=4;
   cout<< solve(n);



    return 0;
}