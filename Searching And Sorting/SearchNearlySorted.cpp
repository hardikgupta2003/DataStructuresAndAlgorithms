#include <iostream>
#include <vector>
using namespace std;

int searchNearlySorted(vector<int> nums,int target){
    int s=0;
    int e=nums.size()-1;
    int mid=s+(e-s)/2;
    
    while(s<=e){
         if(target==nums[mid]){
            return mid;
        }
        else if(target==nums[mid-1]){
            return mid-1;
        }
        else if(target==nums[mid+1]){
            return mid+1;
        }
        else if(target>nums[mid]){
            s=mid+2;
        }
        else{
            e=mid-2;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

int main() {
    vector<int> nums{20,10,50,30,60,40};
    int target = 60;
    
    int ans=searchNearlySorted(nums,target);
    cout<<"searched in nearly sorted array : "<<ans;
    return ans;
    
    
   

    return 0;
}