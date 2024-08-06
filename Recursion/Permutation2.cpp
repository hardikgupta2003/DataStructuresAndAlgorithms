#include "bits/stdc++.h"
using namespace std;

class Solution
{
    vector<vector<int>> ans;
    int n;

public:
    void solve(vector<int> &temp, unordered_map<int, int> &mp)
    {
        if (temp.size() == n)
        {
            ans.push_back(temp);
            return;
        }

        for (auto &it : mp)
        {

            if (it.second == 0)
                continue;
            // do something
            temp.push_back(it.first);
            mp[it.first]--;
            // explore
            solve(temp, mp);
            // undo that something
            temp.pop_back();
            mp[it.first]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        n = nums.size();
        unordered_map<int, int> mp;
        vector<int> temp;
        for (auto &num : nums)
        {
            mp[num]++;
        }

        solve(temp, mp);

        return ans;
    }
};

class Solution
{
public:
    int n;
    vector<vector<int>> ans;
    void backtrack(vector<int> &nums, int index)
    {
        if (index == n)
        {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> set;
        for (int i = index; i < nums.size(); i++)
        {
            if (set.find(nums[i]) != set.end())
            {
                continue;
            }
            set.insert(nums[i]);
            swap(nums[i], nums[index]);

            backtrack(nums, index + 1);

            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        n = nums.size();
        backtrack(nums, 0);
        return ans;
    }
};
