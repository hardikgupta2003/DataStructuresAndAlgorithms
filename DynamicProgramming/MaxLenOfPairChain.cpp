#include <bits/stdc++.h>
using namespace std;

// recursion
class Solution
{
public:
    int flc(vector<vector<int>> &pairs, int &prev, int curr, int n)
    {
        if (curr >= n)
            return 0;

        int include = 0;
        if (prev == -1 || pairs[curr][0] > pairs[prev][1])
        {
            include = 1 + flc(pairs, curr, curr + 1, n);
        }
        int exclude = 0 + flc(pairs, prev, curr + 1, n);

        return max(include, exclude);
    }
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        int curr = 0;
        int prev = -1;
        sort(pairs.begin(), pairs.end());
        return flc(pairs, prev, curr, n);
    }
};

// memoization

class Solution
{
public:
    int flcMemo(vector<vector<int>> &pairs, int &prev, int curr, int n, vector<vector<int>> &dp)
    {
        if (curr >= n)
            return 0;

        if (dp[prev + 1][curr + 1] != -1)
            return dp[prev + 1][curr + 1];
        int include = 0;
        if (prev == -1 || pairs[curr][0] > pairs[prev][1])
        {
            include = 1 + flcMemo(pairs, curr, curr + 1, n, dp);
        }
        int exclude = 0 + flcMemo(pairs, prev, curr + 1, n, dp);

        return dp[prev + 1][curr + 1] = max(include, exclude);
    }
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        int curr = 0;
        int prev = -1;
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return flcMemo(pairs, prev, curr, n, dp);
    }
};
//tabulation

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        int maxAns = 1;
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[j][1] < pairs[i][0])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxAns = max(maxAns, dp[i]);
                }
            }
        }
        return maxAns;
    }
};
