#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();

        deque<int> dq;                  // stores indices of prefix sums in increasing order
        vector<long long> prefix(n, 0); // cumulative sum array

        int result = INT_MAX; // to store the minimum subarray length
        int j = 0;

        while (j < n)
        {
            // Step 1: Calculate prefix sum
            if (j == 0)
            {
                prefix[j] = nums[j]; // First element is itself
            }
            else
            {
                prefix[j] = prefix[j - 1] + nums[j]; // Cumulative sum
            }

            // Step 2: If current prefix sum is >= k, update result
            if (prefix[j] >= k)
            {
                result = min(result, j + 1); // Entire subarray from 0 to j
            }

            // Step 3: Shrink window from the left if the sum condition is met
            while (!dq.empty() && prefix[j] - prefix[dq.front()] >= k)
            {
                result = min(result, j - dq.front()); // Update result
                dq.pop_front();                       // Remove index as it's no longer useful
            }

            // Step 4: Maintain monotonic order in deque
            while (!dq.empty() && prefix[j] <= prefix[dq.back()])
            {
                dq.pop_back(); // Remove larger prefix sums as they're unnecessary
            }

            // Step 5: Add current index to deque
            dq.push_back(j);
            j++;
        }

        // If no subarray is found, return -1
        return result == INT_MAX ? -1 : result;
    }
};
