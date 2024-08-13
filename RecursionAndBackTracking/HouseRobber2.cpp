#include <iostream>
#include <vector>
using namespace std;

 int solve(vector<int>& nums,int index,int end){
        //base case
        
        if(index>end){
            return 0;

        }
        //robbery kari hai ith house me
        int option1=nums[index]+solve(nums,index+2,end);

        //robbery nahi kari hai ith house me
        int option2=0+solve(nums,index+1,end);

        int finalAns=max(option1,option2);
        return finalAns;
    }
    int rob(vector<int>& nums) {
        int index=0;
        int end=nums.size();
        if(end==1){
            return nums[index];
            
        }
        //robbed house 1
        int option1=solve(nums,index,end-2);
        //don't robbed house 1
        int option2=solve(nums,index+1,end-1);
        int ans=max(option1,option2);
        cout<<ans;
        return ans;
        
    }

int main(){
    vector<int> nums{1,2,3,1};
    rob(nums);
    

    return 0;

}