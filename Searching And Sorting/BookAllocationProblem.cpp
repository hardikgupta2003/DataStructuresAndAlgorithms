// book allocation problem || Split array largest sum 
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossibleSolution(vector<int> &nums, int &n, int k, int sol)
    {
        int pageSum = 0;
        int c = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > sol)
            {
                return false;
            }
            if (pageSum + nums[i] > sol)
            {
                c++;
                pageSum = nums[i];
                if (c > k)
                {
                    return false;
                }
            }
            else
            {
                pageSum += nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k > n)
            return -1;

        int start = 0;
        int end = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while (start <= end)
        {
            int mid = (start + end) >> 1;
            if (isPossibleSolution(nums, n, k, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};