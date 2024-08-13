//leetcode

#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int> &coins,int amount){
    if(amount==0){
        return 0;
    }
    if(amount<0){
        return INT8_MIN;
    }
    int mini=INT8_MAX;
    int ans=INT8_MAX;

    for(int i=0;i<coins.size();i++){
        int coin=coins[i];
    // current tabhi use krenge jab uski value amount se kam ya equal hogi
    if(coin<=amount){
        int recAns=solve(coins,amount-coin);
        if(recAns!=INT8_MAX){
            ans=1+recAns;
        }
        mini=min(mini,ans);

    }
    
    }
    return mini;
}
int coinChange(vector<int> &coins,int amount){
    int ans=solve(coins,amount);
    if(ans==INT8_MAX){
        return -1;
    }
    else{
        return ans;
    }

}

int main(){
    vector<int> coins{1,2,5};
    int amount=11;
    int ans=coinChange(coins,amount);
    cout<<ans;

}