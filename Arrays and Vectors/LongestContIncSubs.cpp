#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int lcs = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            int maxi = 1;
            for (int j = i; j < nums.size(); j++)
            {
                if (j + 1 < nums.size() && nums[j] < nums[j + 1])
                {
                    maxi++;
                }
                else
                {
                    break;
                }
            }
            lcs = max(maxi, lcs);
        }
        return lcs;
    }
};