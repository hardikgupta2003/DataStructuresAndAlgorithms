//leetcode medium
// partitionEqualSubsetSum

#include <bits/stdc++.h>
using namespace std;

// recursion
class Solution
{
public:
    bool solveByRecursion(vector<int> &nums, int index, int sum, int target)
    {
        if (index >= nums.size())
            return 0;
        if (sum > target)
            return 0;
        if (sum == target)
            return true;

        int include = solveByRecursion(nums, index + 1, sum + nums[index], target);
        int exclude = solveByRecursion(nums, index + 1, sum, target);

        return include || exclude;
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
        }
        if (sum & 1)
        {
            return false;
        }
        int target = sum / 2;
        int currSum = 0;
        bool ans = solveByRecursion(nums, 0, currSum, target);
        return ans;
    }
};
// by memoization
class Solution
{
public:
    bool solveBymemo(vector<int> &nums, int index, int sum, int target, vector<vector<int>> &dp)
    {
        if (index >= nums.size())
            return 0;
        if (sum > target)
            return 0;
        if (sum == target)
            return true;

        if (dp[index][sum] != -1)
            return dp[index][sum];
        bool include = solveBymemo(nums, index + 1, sum + nums[index], target, dp);
        bool exclude = solveBymemo(nums, index + 1, sum, target, dp);

        return dp[index][sum] = (include || exclude);
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0, index = 0;
        for (auto num : nums)
        {
            sum += num;
        }
        if (sum & 1)
        {
            return false;
        }
        int target = sum / 2;
        int currSum = 0;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        bool ans = solveBymemo(nums, index, currSum, target, dp);
        return ans;
    }
};

// tabulation
class Solution
{
public:
    bool solveByTab(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(target + 1, 0));

        for (int row = 0; row <= n; row++)
        {
            dp[row][target] = 1;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int s = target; s >= 0; s--)
            {
                bool include = 0;
                if (s + nums[i] <= target)
                {
                    include = dp[i + 1][s + nums[i]];
                }
                bool exclude = dp[i + 1][s];

                dp[i][s] = (include || exclude);
            }
        }
        return dp[0][0];
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
        }
        if (sum & 1)
        {
            return false;
        }
        int target = sum / 2;
        int n = nums.size();
        bool ans = solveByTab(nums, target);
        return ans;
    }
};