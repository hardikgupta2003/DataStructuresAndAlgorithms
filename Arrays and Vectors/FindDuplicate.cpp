// approach 1


#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }

int main(){
    vector<int> nums{1,3,4,2,2};
    int ans=findDuplicate(nums);
    cout<<ans<<" ";
    return 0;
}