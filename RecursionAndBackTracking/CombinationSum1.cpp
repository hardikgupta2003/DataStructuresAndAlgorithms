#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &arr, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(arr, 0, target, ans, ds);

        return ans;
    }

    void findCombination(vector<int> &arr, int idx, int target, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        if (idx == arr.size())
        {
            return;
        }

        if (target >= arr[idx])
        {
            ds.push_back(arr[idx]);
            findCombination(arr, idx, target - arr[idx], ans, ds);
            ds.pop_back();
        }
        findCombination(arr, idx + 1, target, ans, ds);
    }
};

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &arr, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(arr, 0, target, ans, ds);

        return ans;
    }

    void findCombination(vector<int> &arr, int idx, int target, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        if (idx == arr.size())
        {
            return;
        }

        if (target >= arr[idx])
        {
            ds.push_back(arr[idx]);
            findCombination(arr, idx, target - arr[idx], ans, ds);
            ds.pop_back();
        }
        findCombination(arr, idx + 1, target, ans, ds);
    }
};