#include <bits/stdc++.h>
using namespace std;

// recursion
class Solution
{
public:
    int findPaths(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return 0;
        }
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        int right = findPaths(i, j + 1, m, n, dp);
        int down = findPaths(i + 1, j, m, n, dp);

        return dp[i][j] = right + down;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findPaths(0, 0, m, n, dp);
    }
};

// dp
class Solution
{
public:
    int findPaths(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return 0;
        }
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        int right = findPaths(i, j + 1, m, n, dp);
        int down = findPaths(i + 1, j, m, n, dp);

        return dp[i][j] = right + down;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findPaths(0, 0, m, n, dp);
    }
};