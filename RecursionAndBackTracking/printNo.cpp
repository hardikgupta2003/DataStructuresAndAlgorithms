
#include <iostream>
using namespace std;

void printNo(int n){
    int ans;
    if(n==0){
        return;
    }
   
    
    printNo(n/10);
    cout<<n%10<<" ";
    
    
}

int main() {
    int n=4231;
    printNo(n);
    return 0;
}