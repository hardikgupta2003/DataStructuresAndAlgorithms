// approach 1


#include <bits/stdc++.h>
using namespace std;

// int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size()-1;i++){
//             if(nums[i]==nums[i+1]){
//                 return nums[i];
//             }
//         }
//         return -1;
//     }

// approach 3
//   int findDuplicate(vector<int>& nums) {
//        int ans=-1;
//        for(int i=0;i<nums.size();i++){
//            int index=abs(nums[i]);

//            //already visited
//            if(nums[index]<0){
//                ans=index;
//                break;
//            }

//            //not visited? then mark visited
//            nums[index]*=-1;

//        }
//        return ans;
//     }

// approach 3

 int findDuplicate(vector<int>& nums) {
      while(nums[0]!=nums[nums[0]]){
          swap(nums[0],nums[nums[0]]);
      }
      return nums[0];
    }
int main(){
    vector<int> nums{1,3,4,2,2};
    int ans=findDuplicate(nums);
    cout<<ans<<" ";
    return 0;
}