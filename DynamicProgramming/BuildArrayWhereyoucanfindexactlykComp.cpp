// leetcode hard
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int N, M, K;
    int MOD = 1e9 + 7;
    int dp[51][51][101];
    int solve(int index, int searchCost, int maxSoFar)
    {
        if (index == N)
        {
            return searchCost == K ? 1 : 0;
        }
        if (dp[index][searchCost][maxSoFar] != -1)
            return dp[index][searchCost][maxSoFar];

        int result = 0;
        for (int i = 1; i <= M; i++)
        {
            if (i > maxSoFar)
            {
                result = (result + solve(index + 1, searchCost + 1, i)) % MOD;
            }
            else
            {
                result = (result + solve(index + 1, searchCost, maxSoFar)) % MOD;
            }
        }
        return dp[index][searchCost][maxSoFar] = result;
    }

    int numOfArrays(int n, int m, int k)
    {
        N = n;
        M = m;
        K = k;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};
