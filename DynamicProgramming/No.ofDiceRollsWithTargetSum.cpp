// leetcode medium
// number of dice rolls with target sum
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/
#include <bits/stdc++.h>
using namespace std;

// by recursion
class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        if (target == 0 && n != 0)
            return 0;
        if (target != 0 && n == 0)
            return 0;
        if (target == 0 && n == 0)
            return 1;

        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            if (target - i >= 0)
            {
                ans += numRollsToTarget(n - 1, k, target - i);
            }
        }
        return ans;
    }
};

// by memoization
class Solution
{
public:
    long long int mod = 1000000007;
    int solveByMemoization(int n, int k, int target, vector<vector<int>> &dp)
    {
        if (target == 0 && n != 0)
            return 0;
        if (target != 0 && n == 0)
            return 0;
        if (target == 0 && n == 0)
            return 1;

        int ans = 0;
        if (dp[n][target] != -1)
            return dp[n][target];
        for (int i = 1; i <= k; i++)
        {
            long long int recAns = 0;
            if (target - i >= 0)
            {
                recAns = solveByMemoization(n - 1, k, target - i, dp);
            }
            ans = (ans + recAns) % mod;
        }
        return dp[n][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solveByMemoization(n, k, target, dp);
    }
};

// another approach
class Solution
{
public:
    long long int mod = 1000000007;
    int solveByMemoization(int n, int k, int target, int diceUsed, int currSum, vector<vector<int>> &dp)
    {
        if (diceUsed == n && currSum != target)
            return 0;
        if (diceUsed != n && currSum == target)
            return 0;
        if (diceUsed == n && currSum == target)
            return 1;

        if (dp[diceUsed][currSum] != -1)
            return dp[diceUsed][currSum];
        int ans = 0;
        for (int face = 1; face <= k; face++)
        {
            long long int recAns = 0;
            if (currSum + face <= target)
            {
                recAns = solveByMemoization(n, k, target, diceUsed + 1, currSum + face, dp);
            }
            ans = (ans + recAns) % mod;
        }
        return dp[diceUsed][currSum] = ans;
    }

    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        int diceUsed = 0;
        int currSum = 0;
        return solveByMemoization(n, k, target, diceUsed, currSum, dp);
    }
};

// tabulation
class Solution {
public:
    long long int mod = 1000000007;
    int solveByTabulation(int n, int k, int target) {
        vector<vector<int>> dp(n + 2, vector<int>(target + 1, 0));

        dp[n][target] = 1;

        for (int diceUsed = n-1; diceUsed >= 0; diceUsed--) {
            for (int sum = target; sum >= 0; sum--) {
                int ans = 0;
                for (int face = 1; face <= k; face++) {
                    long long int recAns = 0;
                    if (sum + face <= target) {
                        recAns = dp[diceUsed + 1][sum + face];
                    }
                    ans = (ans + recAns) % mod;
                }
                dp[diceUsed][sum] = ans;
            }
        }
        return dp[0][0];
    }

    int numRollsToTarget(int n, int k, int target) {
        int diceUsed = 0;
        int currSum = 0;
        return solveByTabulation(n, k, target);
    }
};