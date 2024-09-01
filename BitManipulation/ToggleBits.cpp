#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int m = n;
    int ans = 0;
    int shiftIndex=0;
    for(int i=1;i<=32;i++){
        if((n & 1) == 1){
            shiftIndex = i;
        } 
        n = n>>1;
    }
    cout<<shiftIndex<<endl;
    int mask = (-1 << (shiftIndex));
    ans = m ^ ~(mask);
    cout<<ans<<endl;
    return 0;
}