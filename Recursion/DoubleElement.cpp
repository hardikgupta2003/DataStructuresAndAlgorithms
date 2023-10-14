#include <iostream>
#include <vector>
using namespace std;

void doublee(vector<int> &nums,int index){
    if(index>=nums.size()){
        return ;
    }
    
    
        nums[index]=2*nums[index];
        cout<<nums[index]<<" ";

    doublee(nums,index+1);
  
}
int main() {
    vector<int> nums{10,20,30,40};
    int index=0;
    doublee(nums,index);
    
    for(int i=0;i<nums.size();i++){
        
    }

    return 0;
}