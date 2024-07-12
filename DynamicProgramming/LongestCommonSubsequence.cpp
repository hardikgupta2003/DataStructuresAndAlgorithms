#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // recursion
    int LCS(string &a, string &b, int i, int j)
    {
        if (i >= a.size() || j >= b.size())
            return 0;

        int ans = 0;
        // if they match
        if (a[i] == b[j])
        {
            ans = 1 + LCS(a, b, i + 1, j + 1);
        }
        // if they dont match
        else
        {
            ans = 0 + max(LCS(a, b, i, j + 1), LCS(a, b, i + 1, j));
        }
        return ans;
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        return LCS(text1, text2, 0, 0);
    }
};

// by memoization
class Solution
{
public:
    // memoization
    int LCS(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= a.size() || j >= b.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        // if they match
        if (a[i] == b[j])
        {
            ans = 1 + LCS(a, b, i + 1, j + 1, dp);
        }
        // if they dont match
        else
        {
            ans = 0 + max(LCS(a, b, i, j + 1, dp), LCS(a, b, i + 1, j, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return LCS(text1, text2, 0, 0, dp);
    }
};

// by Tabulation
    int solveUsingTabulation(string a, string b)
    {
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

        for (int i_index = a.length() - 1; i_index >= 0; i_index--)
        {
            for (int j_index = b.length() - 1; j_index >= 0; j_index--)
            {
                int ans = 0;
                if (a[i_index] == b[j_index])
                {
                    ans = 1 + dp[i_index + 1][j_index + 1];
                }
                else
                {
                    ans = 0 + max(dp[i_index][j_index + 1], dp[i_index + 1][j_index]);
                }
                dp[i_index][j_index] = ans;
            }
        }
        return dp[0][0];
    }

    int solveUsingTabulationSO(string a, string b)
    {
        // vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));
        vector<int> curr(a.length() + 1, 0);
        vector<int> next(a.length() + 1, 0);

        for (int j_index = b.length() - 1; j_index >= 0; j_index--)
        {
            for (int i_index = a.length() - 1; i_index >= 0; i_index--)
            {

                int ans = 0;
                if (a[i_index] == b[j_index])
                {
                    ans = 1 + next[i_index + 1];
                }
                else
                {
                    ans = 0 + max(next[i_index], curr[i_index + 1]);
                }
                curr[i_index] = ans;
            }
            // shifting
            next = curr;
        }
        return next[0];
    }
    // S0 by rows
    class Solution
    {
    public:
        int LPS(string &a, string &b)
        {
            vector<int> curr(b.size() + 1, 0);
            vector<int> next(b.size() + 1, 0);

            int ans = 0;
            for (int i = a.size() - 1; i >= 0; i--)
            {
                for (int j = b.size() - 1; j >= 0; j--)
                {
                    if (a[i] == b[j])
                    {
                        ans = 1 + next[j + 1];
                    }
                    else
                    {
                        ans = 0 + max(next[j], curr[j + 1]);
                    }
                    curr[j] = ans;
                }
                // shifting
                next = curr;
            }
            return next[0];
        }
        int longestPalindromeSubseq(string s)
        {
            string rs = s;
            reverse(rs.begin(), rs.end());
            return LPS(s, rs);
        }
    };

    int longestCommonSubsequence(string text1, string text2)
    {
        int i = 0;
        int j = 0;
        // vector<vector<int> > dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        int ans = solveUsingTabulation(text1, text2);
        return ans;
    }
