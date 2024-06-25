#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solve(string &str, int start, int end)
    {
        // base case
        if (start >= end)
        {
            return true;
        }

        if (!isalnum(str[start]))
        {
            return solve(str, start + 1, end);
        }
        else if (!isalnum(str[end]))
        {
            return solve(str, start, end - 1);
        }
        else if (tolower(str[start]) != tolower(str[end]))
        {
            return false;
        }

        return solve(str, start + 1, end - 1);
    }
    bool isPalindrome(string str)
    {
        int start = 0;
        int end = str.length() - 1;

        bool ans = solve(str, start, end);
        return ans;
    }
};