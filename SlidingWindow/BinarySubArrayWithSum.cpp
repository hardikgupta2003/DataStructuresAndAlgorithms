#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int count = 0;
        int start = 0;
        int end = 0;
        int sum = 0;
        int prefixZero = 0;

        while (end < n)
        {
            // sum me include karo value
            sum = sum + nums[end];
            while (start < end && (sum > goal || nums[start] == 0))
            {
                // minimise
                if (nums[start] == 1)
                {
                    prefixZero = 0;
                }
                else
                {
                    prefixZero += 1;
                }
                // curr element, pointed by start, should be removed from sum
                sum = sum - nums[start];
                start++;
            }
            if (sum == goal)
            {
                count += prefixZero + 1;
            }
            // explore
            end++;
        }
        return count;
    }
};