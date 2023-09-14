#include <iostream>
#include <vector>
using namespace std;

    void sortColors(vector<int>& nums) {
        int l=0;
        int m=0;
        int h=nums.size()-1;
        int n=nums.size();
       while(m<=h){
           if(nums[m]==0){
            swap(nums[m],nums[l]);
            m++;
            l++;

        }
        else if(nums[m]==1){
            m++;
        }
        else{
            swap(nums[m],nums[h]);
            h--;

        }
       } 
         for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
    }

    int main(){
            vector<int> nums{2,0,2,1,1,0};
            sortColors(nums);
        return 0;
    }