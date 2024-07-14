// leetcode medium
// longest increasing subsequnce
#include <bits/stdc++.h>
using namespace std;

// by memoization
class Solution
{
public:
    int solve(vector<int> &nums, int prev, int curr, vector<vector<int>> &dp)
    {
        if (curr >= nums.size())
            return 0;

        if (dp[prev + 1][curr] != -1)
            return dp[prev + 1][curr];

        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev])
        {
            include = 1 + solve(nums, curr, curr + 1, dp);
        }
        int exclude = 0 + solve(nums, prev, curr + 1, dp);
        dp[prev + 1][curr] = max(include, exclude);
        return dp[prev + 1][curr];
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        return solve(nums, -1, 0, dp);
    }
};
// tabulation
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int currIndex = n - 1; currIndex >= 0; currIndex--)
        {
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--)
            {
                int include = 0;
                if (prevIndex == -1 || nums[currIndex] > nums[prevIndex])
                {
                    include = 1 + dp[currIndex + 1][currIndex + 1];
                }
                int exclude = 0 + dp[currIndex + 1][prevIndex + 1];
                dp[currIndex][prevIndex + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
};

// easy and optimized approach
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        int maxi = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] > nums[prev])
                {
                    dp[i] = max(1 + dp[prev], dp[i]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
    // highly optimized approach
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> ans;
        ans.push_back(nums[0]);
        for (auto num : nums)
        {
            if (num > ans.back())
            {
                ans.push_back(num);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), num) - ans.begin();
                ans[index] = num;
            }
        }
        return ans.size();
    }
};