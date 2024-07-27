#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int BS(vector<int> &nums, int start, int key)
    {
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] == key)
            {
                return mid;
            }
            else if (nums[mid] > key)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (BS(nums, i + 1, nums[i] + k) != -1)
            {
                ans.insert({nums[i], nums[i] + k});
            }
        }
        return ans.size();
    }
};