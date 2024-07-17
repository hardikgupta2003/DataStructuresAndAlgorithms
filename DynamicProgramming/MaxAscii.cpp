// leetcode medium 
// maximum ascii delete sum for two strings
#include <bits/stdc++.h>
using namespace std;

// by recursion
class Solution
{
public:
    int solve(string &a, string &b, int i, int j)
    {
        int sum = 0;
        if (i == a.size() && j == b.size())
            return 0;

        else if (i >= a.size())
        {
            for (int index = j; index < b.size(); index++)
            {
                sum += (int)b[index];
            }
        }
        else if (j >= b.size())
        {
            for (int index = i; index < a.size(); index++)
            {
                sum += (int)a[index];
            }
        }
        else if (a[i] == b[j])
        {
            return solve(a, b, i + 1, j + 1);
        }
        else
        {
            int op1 = a[i] + solve(a, b, i + 1, j);
            int op2 = b[j] + solve(a, b, i, j + 1);
            sum = min(op1, op2);
        }

        return sum;
    }

    int minimumDeleteSum(string a, string b)
    {
        return solve(a, b, 0, 0);
    }
};

// tabulation
class Solution
{
public:
    int solveByMemo(string &a, string &b)
    {
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
        int sum = 0;

        for (int i = a.size() - 1; i >= 0; i--)
        {
            dp[i][b.size()] = a[i] + dp[i + 1][b.size()];
        }

        for (int i = b.size() - 1; i >= 0; i--)
        {
            dp[a.size()][i] = b[i] + dp[a.size()][i + 1];
        }

        for (int i = a.size() - 1; i >= 0; i--)
        {
            for (int j = b.size() - 1; j >= 0; j--)
            {
                if (a[i] == b[j])
                {
                    sum = dp[i + 1][j + 1];
                }
                else
                {
                    int op1 = a[i] + dp[i + 1][j];
                    int op2 = b[j] + dp[i][j + 1];
                    sum = min(op1, op2);
                }
                dp[i][j] = sum;
            }
        }
        return dp[0][0];
    }

    int minimumDeleteSum(string a, string b)
    {
        return solveByMemo(a, b);
    }
};