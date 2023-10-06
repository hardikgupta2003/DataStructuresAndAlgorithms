#include <iostream>
#include <vector>
using namespace std;

  bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int n=row*col;
        int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;

        while(s<=e){
            int rowIndex = mid/col;
            int colIndex = mid%col;
            int element = matrix[rowIndex][colIndex];

            if(target==element){
                return true;
            }
            else if(target>element){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return false;
    }

int main() {
    vector<vector<int>> nums{{2,4,6,8},{10,12,14,16},{18,20,22,24},{28,34,40,48}};
    int target = 80;
    
    int ans=searchMatrix(nums,target);
    cout<<"searched in 2D sorted array : "<<ans;
    return ans;
    
    
   

    return 0;
}