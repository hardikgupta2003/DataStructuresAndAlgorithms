#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPredecessor(string &a, string &b)
    {
        int m = a.size();
        int n = b.size();
        if (n - m > 1 || n - m != 1)
            return false;

        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (a[i] == b[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return i == m;
    }
    int solve(vector<string> &words, int prev, int curr,
              vector<vector<int>> &dp)
    {
        if (curr >= words.size())
        {
            return 0;
        }
        if (prev != -1 && dp[prev + 1][curr] != -1)
        {
            return dp[prev + 1][curr];
        }
        int include = 0;
        if (prev == -1 || isPredecessor(words[prev], words[curr]))
        {
            include = 1 + solve(words, curr, curr + 1, dp);
        }

        int exclude = 0 + solve(words, prev, curr + 1, dp);

        dp[prev + 1][curr] = max(include, exclude);
        return dp[prev + 1][curr];
    }
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.length() < b.length(); });

        int curr = 0;
        int prev = -1;
        vector<vector<int>> dp(words.size() + 1, vector<int>(words.size(), -1));
        return solve(words, prev, curr, dp);

        return 0;
    }
};