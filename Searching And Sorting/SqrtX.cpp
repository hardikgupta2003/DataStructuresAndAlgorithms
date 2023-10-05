#include<iostream>
#include<vector>
using namespace std;


 int mySqrt(int x) {
        int s=0;
        int e=x;
        long long int mid=s+(e-s)/2;
        long long int ans=-1;
        while(s<=e){
            long long int square=mid*mid;
            if(square==x){
                return mid;
            }
            else if(square>x){
                e=mid-1;
            }
            else{
                ans=mid;
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
int main(){
    int x=68;
    int ans=mySqrt(x);
    cout<<"square root of "<<x<<" is : "<<ans;

    return 0;
}