#include <iostream>
#include <vector>
using namespace std;

  int solve(vector<int>& nums,int index){
        //base case
        if(index>=nums.size()){
            return 0;

        }
        //robbery kari hai ith house me
        int option1=nums[index]+solve(nums,index+2);

        //robbery nahi kari hai ith house me
        int option2=0+solve(nums,index+1);

        int finalAns=max(option1,option2);
        return finalAns;
    }
    int rob(vector<int>& nums) {
        int index=0;
        int ans=solve(nums,index);
        cout<<ans;
        return ans;
        
    }

int main(){
    vector<int> nums{1,2,3,1};
    rob(nums);
    

    return 0;

}