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

    int robWithBottomUp(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> dp(n + 1, 0);

        // Case 1: Exclude the last house
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 2; i <= n - 1; i++) {
            int steal = nums[i - 1] + dp[i - 2];
            int skip = dp[i - 1];
            dp[i] = max(steal, skip);
        }

        int result1 = dp[n - 1];

        // Case 2: Exclude the first house
        dp.assign(n + 1, 0);

        // dp[i] represents the best result for nums[1...i]
        for (int i = 2; i <= n; i++) {
            int steal = nums[i - 1] + dp[i - 2];
            int skip = dp[i - 1];
            dp[i] = max(steal, skip);
        }

        int result2 = dp[n];

        return max(result1, result2);
    }
    int robWithSpaceOptimization(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        // Case 1: Exclude the last house
        // Consider houses from index 0 to n-2
        int prevPrev = 0;
        int prev = nums[0];
        int ans = nums[0];

        for (int i = 2; i <= n - 1; i++) {
            // Rob current house + maximum money from two houses back
            int steal = nums[i - 1] + prevPrev;

            // Skip current house
            int skip = prev;

            // Choose the maximum money
            ans = max(steal, skip);

            // Update previous two states
            prevPrev = prev;
            prev = ans;
        }

        int result1 = ans;

        // Case 2: Exclude the first house
        // Consider houses from index 1 to n-1
        prevPrev = 0;
        prev = 0;
        ans = 0;

        for (int i = 2; i <= n; i++) {
            // Rob current house + maximum money from two houses back
            int steal = nums[i - 1] + prevPrev;

            // Skip current house
            int skip = prev;

            // Choose the maximum money
            ans = max(steal, skip);

            // Update previous two states
            prevPrev = prev;
            prev = ans;
        }

        int result2 = ans;

        // Return the maximum from both cases
        return max(result1, result2);
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