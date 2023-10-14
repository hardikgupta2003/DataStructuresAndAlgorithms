#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void search(vector<int> &nums,int index,int target,vector<int> &ans){
    
   
    
    if(index>=nums.size()){
        return ;
    }
    if(nums[index]==target){
        ans.push_back(index);
       
        
    }
    search(nums,index+1,target,ans);
    
  
}
int main() {
    vector<int> nums{10,20,30,20,90};
    vector<int> ans;
    int index=0;
    int target=20;
    search(nums,index,target,ans);
    for(int i=0;i<ans.size();i++){
         cout<<ans[i]<<" ";
    }
   
    
    
   
    return 0;
}