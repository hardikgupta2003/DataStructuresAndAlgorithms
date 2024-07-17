#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solveByMemo(int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (n < 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];
        int sq = sqrt(n);
        int ans = INT_MAX;
        for (int i = 1; i <= sq; ++i)
        {
            int perfectSq = i * i;
            int perfSqCount = 1 + solveByMemo(n - perfectSq, dp);
            if (perfSqCount < ans)
            {
                ans = perfSqCount;
            }
            dp[n] = ans;
        }
        return dp[n];
    }
    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        return solveByMemo(n, dp);
    }
};

// by tabulation
class Solution
{
public:
    int solveByTab(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        int ans = INT_MAX;
        for (int it = 1; it <= n; it++)
        {
            int sq = sqrt(it);
            for (int i = 1; i <= sq; ++i)
            {
                int perfectSq = i * i;
                if (it - perfectSq >= 0)
                {
                    dp[it] = min(dp[it], 1 + dp[it - perfectSq]);
                }
            }
        }
        return dp[n];
    }
    int numSquares(int n)
    {
        return solveByTab(n);
    }
};