#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MAX;
        int start = 0;
        int end = 0;
        int sum = 0;
        while (end < n)
        {
            // sum me include karo value
            sum = sum + nums[end];
            // ho sakta hai sum == target ho
            // ho sakta hai sum > target ho
            // ho sakta hai sum < target ho
            while (sum >= target)
            {
                // minimise
                ans = min(ans, end - start + 1);

                // curr element, pointed by start, should be removed from sum
                sum = sum - nums[start];
                start++;
            }
            // loop se bahar matlab guarentee -> sum < target
            // explore
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};