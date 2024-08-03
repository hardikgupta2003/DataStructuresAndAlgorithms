#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> mp;
        for (auto num : arr)
        {
            mp[num]++;
        }
        for (auto num : target)
        {
            mp[num]--;
            if (mp[num] == 0)
            {
                mp.erase(num);
            }
        }
        if (mp.empty())
        {
            return true;
        }
        return false;
    }
};

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        sort(target.begin(), target.end());
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] != target[i])
                return false;
        }
        return true;
    }
};