// using kadane's algorithm
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxi = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // step 1
            sum += nums[i];
            // step 2
            maxi = max(maxi, sum);

            // step 3
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxi = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            // step 1
            sum = max(nums[i], nums[i] + sum);
            // step 2
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};