// leetcode medium
// guess number higher or lower 2
// https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
// code

#include <bits/stdc++.h>
using namespace std;

//by recursion
class Solution
{
public:
    int solveByRecursion(int start, int end)
    {
        if (start >= end)
            return 0;

        int ans = INT_MAX;
        for (int i = start; i <= end; i++)
        {
            ans = min(ans, i + max(solveByRecursion(start, i - 1), solveByRecursion(i + 1, end)));
        }
        return ans;
    }
    int getMoneyAmount(int n)
    {
        int start = 1;
        int end = n;
        return solveByRecursion(start, end);
    }
};

// by memoization
class Solution
{
public:
    int solveByMemoization(int start, int end, vector<vector<int>> &dp)
    {
        if (start >= end)
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        int ans = INT_MAX;
        for (int i = start; i <= end; i++)
        {
            ans = min(ans, i + max(solveByMemoization(start, i - 1, dp), solveByMemoization(i + 1, end, dp)));
        }
        return dp[start][end] = ans;
    }
    int getMoneyAmount(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int start = 1;
        int end = n;
        return solveByMemoization(start, end, dp);
    }
};

// using tabulation
class Solution
{
public:
    int solveTabulation(int &n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int start = n; start >= 1; start--)
        {
            for (int end = 1; end <= n; end++)
            {

                if (start >= end)
                {
                    continue;
                }
                int ans = INT_MAX;
                for (int i = start; i <= end; i++)
                {
                    ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
                }
                dp[start][end] = ans;
            }
        }
        return dp[1][n];
    }
    int getMoneyAmount(int n) { return solveTabulation(n); }
};
