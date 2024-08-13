#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> result;

public:
    void combinations(int start, int k, int n, vector<int> &temp)
    {
        if (k == 0)
        {
            result.push_back(temp);
            return;
        }
        if (start > n)
            return;

        // do something
        temp.push_back(start);

        // explore
        combinations(start + 1, k - 1, n, temp);

        // undo that thing
        temp.pop_back();

        // explore solve after undoing
        combinations(start + 1, k, n, temp);
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;
        combinations(1, k, n, temp);
        return result;
    }
};

class Solution
{
    vector<vector<int>> result;

public:
    void combinations(int start, int k, int n, vector<int> &temp)
    {
        if (k == 0)
        {
            result.push_back(temp);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            // do something
            temp.push_back(i);

            // explore
            combinations(i + 1, k - 1, n, temp);

            // undo that thing
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;
        combinations(1, k, n, temp);
        return result;
    }
};