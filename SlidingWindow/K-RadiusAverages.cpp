#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int windowSize = 2 * k + 1;
        int n = nums.size();
        vector<int> ans(n, -1);
        // base case
        if (k == 0)
            return nums;
        if (n < windowSize)
            return ans;
        // calculate prefix sum
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = nums[i] + prefix[i - 1];
        }
        // i starting from k bcoz before k it will return -1 (try dry run)
        for (int i = k; i < n - k; i++)
        {
            long long sum = prefix[i + k];

            // checking out of bound
            if ((i - k) > 0)
            {
                sum -= prefix[i - k - 1];
            }
            // storing average
            ans[i] = sum / windowSize;
        }
        return ans;
    }
};

// sliding window
class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int left = 0;
        int i = k;
        int right = i + k;
        int n = nums.size();
        int window = 2 * k + 1;
        // answer vector
        vector<int> ans(n, -1);
        // base case
        if (n < window)
            return ans;
        if (k == 0)
            return nums;
        long long windowSum = 0;
        // process first window
        for (int i = left; i <= right; i++)
        {
            windowSum += nums[i];
        }
        ans[i] = windowSum / window;
        i++;
        right++;
        // process remaining window
        while (right < n)
        {
            int newElement = nums[right];
            int goneElement = nums[left];

            windowSum = windowSum + newElement - goneElement;
            ans[i] = windowSum / window;

            i++;
            right++;
            left++;
        }
        return ans;
    }
};