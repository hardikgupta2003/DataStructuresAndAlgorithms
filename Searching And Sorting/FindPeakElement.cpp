#include<iostream>
#include<vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;

        while(s<e){
            if(nums[mid]<nums[mid+1]){
                //right
                s=mid+1;
            }
            else{
                //left
                e=mid;

            }
            //mid update
            mid=(s+e)/2;
        }
        return s;
    }

int main(){

    vector<int> arr{10,20,30,90,70,60,40,30};
    
    int index = findPeakElement(arr);
    cout<<"peak element  : "<<index<<endl;
    return 0;
}