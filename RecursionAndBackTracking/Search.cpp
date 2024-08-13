#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int search(vector<int> &nums,int index,int target){
    if(index>=nums.size()){
        return -1;
    }
    if(nums[index]==target){
        return index;
    }
    search(nums,index+1,target);
    
}
int main() {
    vector<int> nums{10,20,30,90};
    int index=0;
    int target=90;
    int ans=search(nums,index,target);
   
    cout<<" element found in this vector: "<<ans<<endl;
    
   
    return 0;
}