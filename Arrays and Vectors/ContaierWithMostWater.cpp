#include <iostream>
#include <vector>
using namespace std;


int maxArea(vector<int>& height) {
        int s=0;
        int e=height.size()-1;
        int maxi=-1;
        int store=0;
        while(s<=e){
            store=(e-s)*(min(height[s],height[e]));
            if(height[s]<height[e]){
                s++;

            }
            else{
                e--;
            }
            maxi=max(store,maxi);
        }
        return maxi;
    }

int main(){
    vector<int> v{1,8,6,2,5,4,8,3,7};
    int ans=maxArea(v);
    cout<<"maximum water : "<<ans;




}
