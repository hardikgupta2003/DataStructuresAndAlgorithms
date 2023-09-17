 #include <bits/stdc++.h>

using namespace std;

 int solve(vector<int>& nums){
        
        
        for(int i=0;i<nums.size();++i){
        int lsum=0;
        int rsum=0;
            for(int j=0;j<i;++j)
                lsum += nums[j];
            
            for(int k=i+1;k<nums.size();++k)
                rsum += nums[k];
            cout<<"for index : "<<i<<" left sum : "<<lsum<<" right sum : "<<rsum<<endl;
            if(lsum==rsum)
               return i; 
            
        }
        return -1;
    }
    int main() {
    vector<int> nums{1,7,3,6,5,6};
    cout<<solve(nums);
       
    }


    // leetcode