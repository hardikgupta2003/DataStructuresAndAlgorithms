#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        map<char, int> hash;
        for (auto &i : s)
        {
            hash[i]++;
        }

        int ans = 0;
        bool oddFound = false;
        for (auto &it : hash)
        {
            if (!(it.second & 1))
            {
                ans += it.second;
            }
            else
            {
                int rem = it.second % 2;
                ans += (it.second - rem);
                it.second = it.second - (it.second - rem);
                oddFound = true;
            }
        }
        if (oddFound)
        {
            ans++;
        }
        return ans;
    }
};

class Solution
{
public:
    int longestPalindrome(string s)
    {
        map<char, int> hash;
        for (auto &i : s)
        {
            hash[i]++;
        }

        int ans = 0;
        bool oddFound = false;
        for (auto &it : hash)
        {
            if (!(it.second & 1))
            {
                ans += it.second;
            }
            else
            {
                ans += it.second - 1;
                oddFound = true;
            }
        }
        if (oddFound)
        {
            ans++;
        }
        return ans;
    }
};