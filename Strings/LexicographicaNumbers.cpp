#include <bits/stdc++.h>
using namespace std;

// brute force
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<string> ans;
        vector<int> result;

        // Fill ans with numbers in string form
        for (int i = 1; i <= n; i++)
        {
            ans.push_back(to_string(i));
        }

        // Sort lexicographically by string comparison
        sort(ans.begin(), ans.end());

        // Convert the sorted strings back to integers
        for (auto &i : ans)
        {
            result.push_back(stoi(i));
        }

        return result;
    }
};


// better solution
class Solution
{
public:
    void solve(long long currNum, int n, vector<int> &result)
    {
        if (currNum > n)
            return;

        result.push_back(currNum);
        for (int i = 0; i <= 9; i++)
        {
            long long newNum = (currNum * 10) + i;
            if (newNum > n)
                return;
            solve(newNum, n, result);
        }
    }
    vector<int> lexicalOrder(int n)
    {
        vector<int> result;

        for (int i = 1; i <= 9; i++)
        {
            solve(i, n, result);
        }
        return result;
    }
};
