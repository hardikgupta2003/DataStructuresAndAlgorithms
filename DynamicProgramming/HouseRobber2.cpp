#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int index, int end, vector<int> &dp)
    {
        // base case

        if (index > end)
        {
            return 0;
        }
        if (dp[index] != -1)
        {
            return dp[index];
        }
        // robbery kari hai ith house me
        int option1 = nums[index] + solve(nums, index + 2, end, dp);

        // robbery nahi kari hai ith house me
        int option2 = 0 + solve(nums, index + 1, end, dp);

        dp[index] = max(option1, option2);
        return dp[index];
    }

    int rob(vector<int> &nums)
    {
        vector<int> dp1(nums.size() + 1, -1);
        vector<int> dp2(nums.size() + 1, -1);
        int index = 0;
        int end = nums.size();
        if (end == 1)
        {
            return nums[index];
        }
        // robbed house 1
        int option1 = solve(nums, index, end - 2, dp1);
        // don't robbed house 1
        int option2 = solve(nums, index + 1, end - 1, dp2);
        int ans = max(option1, option2);

        return ans;
    }
};