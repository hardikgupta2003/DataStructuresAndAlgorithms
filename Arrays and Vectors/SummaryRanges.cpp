#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            int start = nums[i];

            while (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1])
            {
                i++;
            }

            if (nums[i] != start)
            {
                ans.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
            else
            {
                ans.push_back(to_string(start));
            }
        }
        return ans;
    }
};