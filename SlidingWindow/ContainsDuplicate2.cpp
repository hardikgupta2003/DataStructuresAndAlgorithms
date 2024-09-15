#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(nums[i]) == mp.end())
            {
                mp[nums[i]] = {1, i};
            }
            else
            {
                if (abs((mp[nums[i]].second) - i) <= k)
                {
                    return true;
                }
                mp[nums[i]].second = i;
            }
        }
        return false;
    }
};