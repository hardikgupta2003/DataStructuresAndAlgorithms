#include<iostream>
#include <vector>
using namespace std;

int findOddOccurence(vector<int> nums){
    int n=nums.size();
    int s=0;
    int e=n-1;

    int mid=s+(e-s)/2;

    while(s<=e){

        //edge case
        if(s==e){
            return nums[s];
        }
        else if(mid&1){   // gives you odd

        if(mid-1>0 && nums[mid]==nums[mid-1]){
            //ans ke left me hai,,,,right me jao
            s=mid+1;
        }
        else{
            //ans ke right me hai ,,,left me jao
            e=mid-1;
        }


        }

        else{   // even case
        if(mid+1<n && nums[mid]==nums[mid+1]){
            //left me hai,,,right me jao...
            s=mid+2;
            //mid+1 already checked
        }
        else{
            //right me hai ya answer pr hai ....
            e=mid;

        }

        }
        mid=s+(e-s)/2;
    }
    return -1;
}

int main(){
    vector<int> nums{5,5,11,11,10,10,4,4,7};
    int ans=findOddOccurence(nums);
    cout<<"final ans : "<<ans;


    return 0;
}