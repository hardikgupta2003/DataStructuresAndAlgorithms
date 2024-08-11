#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int majority = nums.size() - nums.size() / 2;

        unordered_map<int, int> mp;
        for (auto &i : nums)
        {
            mp[i]++;
        }

        for (auto &it : mp)
        {
            if (it.second >= majority)
            {
                return it.first;
            }
        }
        return -1;
    }
};