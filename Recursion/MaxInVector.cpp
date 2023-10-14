#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int findMax(vector<int> &nums,int index,int &maxi){
    if(index>=nums.size()){
        return -1;
    }
    
    
        if(nums[index]>maxi){
            maxi=nums[index];
        }
        
       

    findMax(nums,index+1,maxi);
  
        return maxi;
}
int main() {
    vector<int> nums{10,100,30,90};
    int index=0;
    int maxi=-100;
    findMax(nums,index,maxi);
    cout<<"maximum element in this vector: "<<maxi<<endl;
    
   
    return 0;
}