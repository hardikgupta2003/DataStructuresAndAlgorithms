 #include <bits/stdc++.h>

using namespace std;

//  int solve(vector<int>& nums){
        
        
//         for(int i=0;i<nums.size();++i){
//         int lsum=0;
//         int rsum=0;
//             for(int j=0;j<i;++j)
//                 lsum += nums[j];
            
//             for(int k=i+1;k<nums.size();++k)
//                 rsum += nums[k];
//             cout<<"for index : "<<i<<" left sum : "<<lsum<<" right sum : "<<rsum<<endl;
//             if(lsum==rsum)
//                return i; 
            
//         }
//         return -1;
//     }


// optimized solution by prefix sum 
int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> lsum(n,0);
        vector<int> rsum(n,0);
            cout<<"lsum : ";
        for(int i=1;i<n;i++){
            lsum[i]=lsum[i-1]+nums[i-1];
           cout <<lsum[i]<<" ";
        } cout<<endl;
        cout<<"rsum : ";
        for(int i=n-2;i>=0;i--){
            rsum[i]=rsum[i+1]+nums[i+1];
            cout<<rsum[i]<<" ";
        }
        cout<<endl;
        for(int j=0;j<n;j++){
             
            if(lsum[j]==rsum[j]){
                cout<<"pivot index : ";
                cout<<j<<endl;
                return j;
            }
        }
        return -1;

    }

    
    int main() {
    vector<int> nums{1,7,3,6,5,6};
    cout<<pivotIndex(nums);
       
    }


    // leetcode