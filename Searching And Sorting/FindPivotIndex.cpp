#include<iostream>
#include<vector>
using namespace std;

int findPivotIndex(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;

        while(s<=e){
            if(nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]<nums[mid-1]){
                
                return mid-1;

            }
            else if(nums[s]>nums[mid]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            //mid update
            mid=(s+e)/2;
        }
        return -1;
    }

int main(){

    vector<int> arr{10,12,14,16,2,4,6,8};
    
    int index = findPivotIndex(arr);
    cout<<"pivot index  : "<<index<<endl;
    return 0;
}