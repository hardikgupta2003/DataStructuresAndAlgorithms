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

class Solution {
public:
    // bottom up approach
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long long>> dp(n+1,vector<long long>(2,0));

        if (n == 1) return nums[0];


        for(int i=1;i<n+1;i++){
            // 0-> even, 1-> odd
            //                     take          skip
            dp[i][0] = max(dp[i-1][1]-nums[i-1],dp[i-1][0]);

            //                     take          skip
            dp[i][1] = max(dp[i-1][0]+nums[i-1],dp[i-1][1]);

        }

        return max(dp[n][0],dp[n][1]);
    }
};

// bottom up with top down approach template
class Solution
{
public:
    int n;
    long long solve(vector<int> &nums)
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int flag = 1; flag >= 0; flag--)
            {
                long long skip = dp[index + 1][flag];
                long long val = nums[index];
                if (flag == false)
                {
                    val = -val;
                }
                long long take = val + dp[index + 1][!flag];

                dp[index][flag] = max(skip, take);
            }
        }

        return dp[0][1];
    }
    long long maxAlternatingSum(vector<int> &nums)
    {
        n = nums.size();

        return solve(nums);
    }
};