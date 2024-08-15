#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxEl = *max_element(begin(nums), end(nums));
        vector<int> vec(maxEl + 1, 0);

        // All pairs
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int d = abs(nums[i] - nums[j]);
                vec[d]++;
            }
        }

        for (int d = 0; d <= maxEl; d++)
        {
            k -= vec[d];
            if (k <= 0)
            {
                return d; // returning kth smallest distance
            }
        }
        return -1;
    }
};
class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        int n = nums.size(); // Get the size of the input vector

        // Create a vector to store all pairwise absolute differences
        // The size of this vector is n*(n-1)/2 because that's the number of unique pairs
        vector<int> vec(n * (n - 1) / 2);

        int index = 0; // Initialize an index to keep track of position in 'vec'

        // Iterate over all unique pairs (i, j) where i < j
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int d = abs(nums[i] - nums[j]); // Calculate the absolute difference
                vec[index] = d;                 // Store the difference in 'vec'
                index++;                        // Move to the next position in 'vec'
            }
        }

        // Use nth_element to partially sort the vector such that the k-th smallest element is at position k-1
        nth_element(vec.begin(), vec.begin() + (k - 1), vec.end());

        // Return the k-th smallest distance
        return vec[k - 1];
    }
};
