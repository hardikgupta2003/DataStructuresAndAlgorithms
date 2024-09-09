#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    long long solve(int index, vector<int> &nums, bool flag, vector<vector<long long>> &dp)
    {
        if (index >= n)
        {
            return 0;
        }
        if (dp[index][flag] != -1)
        {
            return dp[index][flag];
        }
        long long skip = solve(index + 1, nums, flag, dp);
        long long val = nums[index];
        if (flag == false)
        {
            val = -val;
        }
        long long take = val + solve(index + 1, nums, !flag, dp);
        return dp[index][flag] = max(skip, take);
    }
    long long maxAlternatingSum(vector<int> &nums)
    {
        n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(0, nums, true, dp);
    }
};