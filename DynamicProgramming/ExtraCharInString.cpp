#include <bits/stdc++.h>
using namespace std;

// recursion
class Solution{
public:
    int solve(string &s, unordered_set<string> &st, int i, int n)
    {
        if (i >= n)
            return 0;

        // take s[i] as an extra char
        int result = 1 + solve(s, st, i + 1, n);

        // take s[i] not as extra char and search in set
        for (int j = i; j < n; j++)
        {
            string curr = s.substr(i, j - i + 1);
            if (st.count(curr))
            {
                result = min(result, solve(s, st, j + 1, n));
            }
        }
        return result;
    }
    int minExtraChar(string s, vector<string> &dict)
    {
        int n = s.size();
        unordered_set<string> st(dict.begin(), dict.end());
        return solve(s, st, 0, n);
    }
};

// top down
class Solution
{
public:
    int solve(string &s, unordered_set<string> &st, int i, int n, vector<int> &dp)
    {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];
        // take s[i] as an extra char
        int result = 1 + solve(s, st, i + 1, n, dp);

        // take s[i] not as extra char and search in set
        for (int j = i; j < n; j++)
        {
            string curr = s.substr(i, j - i + 1);
            if (st.count(curr))
            {
                result = min(result, solve(s, st, j + 1, n, dp));
            }
        }
        return dp[i] = result;
    }
    int minExtraChar(string s, vector<string> &dict)
    {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        unordered_set<string> st(dict.begin(), dict.end());
        return solve(s, st, 0, n, dp);
    }
};

// bottom up
class Solution
{
public:
    int solve(string &s, unordered_set<string> &st, int i, int n)
    {
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            // take s[i] as an extra char
            int result = 1 + dp[i + 1];

            // take s[i] not as extra char and search in set
            for (int j = i; j < n; j++)
            {
                string curr = s.substr(i, j - i + 1);
                if (st.count(curr))
                {
                    result = min(result, dp[j + 1]);
                }
            }
            dp[i] = result;
        }

        return dp[0];
    }
    int minExtraChar(string s, vector<string> &dict)
    {
        int n = s.size();
        unordered_set<string> st(dict.begin(), dict.end());
        return solve(s, st, 0, n);
    }
};