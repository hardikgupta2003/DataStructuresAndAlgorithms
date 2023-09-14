#include <iostream>
#include <vector>
using namespace std;

 int missingNumber(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }

        int totalSum= (n*(n+1))/2;
        int number= totalSum-sum;
        return number;
        
    }

int main(){
            vector<int> nums{3,0,1};
         
           int number= missingNumber(nums);
           cout<<number;
        return 0;
    }
