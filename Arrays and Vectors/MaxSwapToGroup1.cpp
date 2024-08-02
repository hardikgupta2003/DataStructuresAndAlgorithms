#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // Count the number of 1s in the array
    int countOnes(vector<int> &nums)
    {
        int count = 0;
        for (auto num : nums)
        {
            if (num == 1)
            {
                count++;
            }
        }
        return count;
    }

    int minSwaps(vector<int> &nums)
    {
        int oneCount = countOnes(nums);
        if (oneCount == 0)
            return 0; // No 1s, no swaps needed

        int n = nums.size();
        int minSwap = INT_MAX;
        int currentZeroCount = 0;

        // Initial window (first oneCount elements)
        for (int i = 0; i < oneCount; i++)
        {
            if (nums[i] == 0)
            {
                currentZeroCount++;
            }
        }
        minSwap = currentZeroCount;

        // Sliding window over the array with circular consideration
        for (int i = 1; i < n; i++)
        {
            if (nums[(i - 1) % n] == 0)
            {
                currentZeroCount--;
            }
            if (nums[(i + oneCount - 1) % n] == 0)
            {
                currentZeroCount++;
            }
            minSwap = min(minSwap, currentZeroCount);
        }

        return minSwap;
    }
};
