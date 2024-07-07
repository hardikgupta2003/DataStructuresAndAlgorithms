#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solveByRecMemo(int n, vector<int> &dp)
    {
        // base case
        if (n == 0 || n == 1)
            return n;

        // step 3: if answer exist in dp array , then return it
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // step 2: store the answer in dp array
        dp[n] = solveByRecMemo(n - 1, dp) + solveByRecMemo(n - 2, dp);
        return dp[n];
    }
    // tabulation method
    int solveByTabulation(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
            return n;
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // space optimization
    int solveByTabulationSO(int n)
    {
        if (n == 0 || n == 1)
            return n;
        int prev = 0;
        int curr = 1;
        int ans = 0;
        for (int i = 2; i <= n; i++)
        {
            ans = prev + curr;
            prev = curr;
            curr = ans;
        }
        return ans;
    }
    int fib(int n)
    {
        // step 1: create dp array
        vector<int> dp(n + 1, -1);
        // return solveByRecMemo(n,dp);
        // return solveByTabulation(n,dp);
        return solveByTabulationSO(n);
    }
};