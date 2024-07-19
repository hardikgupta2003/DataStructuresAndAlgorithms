#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<string> &wordDict, string &word)
    {
        for (auto i : wordDict)
        {
            if (word == i)
                return true;
        }
        return false;
    }
    bool solve(string &s, vector<string> &wordDict, int start, vector<int> &dp)
    {
        if (start == s.size())
            return true;

        if (dp[start] != -1)
            return dp[start];
        // solve one case
        bool flag = false;
        string word = "";
        for (int i = start; i < s.size(); i++)
        {
            word += s[i];
            if (check(wordDict, word))
            {
                flag = flag || solve(s, wordDict, i + 1, dp);
            }
        }
        return dp[start] = flag;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size() + 1, -1);
        return solve(s, wordDict, 0, dp);
    }
};

// by tabulation
class Solution
{
public:
    bool check(vector<string> &wordDict, string &word)
    {
        for (auto i : wordDict)
        {
            if (word == i)
                return true;
        }
        return false;
    }
    bool solve(string &s, vector<string> &wordDict)
    {
        vector<int> dp(s.size() + 1, 0);
        dp[s.size()] = true;

        for (int it = s.size() - 1; it >= 0; it--)
        {
            bool flag = false;
            string word = "";
            for (int i = it; i < s.size(); i++)
            {
                word += s[i];
                if (check(wordDict, word))
                {
                    flag = flag || dp[i + 1];
                }
            }
            dp[it] = flag;
        }
        return dp[0];
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        return solve(s, wordDict);
    }
};