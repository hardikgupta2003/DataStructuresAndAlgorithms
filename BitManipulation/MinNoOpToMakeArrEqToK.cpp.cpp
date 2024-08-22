#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int num = nums[0];
        int flips = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            num ^= nums[i];
        }
        num = num ^ k;
        while (num != 0)
        {
            flips++;

            num = num & (num - 1);
        }
        return flips;
    }
};

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int flips = 0;

        // Iterate over each bit position (from 0 to 31)
        for (int i = 0; i < 32; i++)
        {
            int oneCount = 0;
            int zeroCount = 0;

            // Check each number in the array for the i-th bit
            for (auto &num : nums)
            {
                if ((num & (1 << i)) != 0)
                {
                    oneCount++;
                }
                else
                {
                    zeroCount++;
                }
            }

            // Calculate the i-th bit of k
            int kBit = (k & (1 << i)) != 0;

            // If the i-th bit of k is 1, we need an odd number of 1's in that bit position
            // If the i-th bit of k is 0, we need an even number of 1's in that bit position
            if ((kBit == 1 && (oneCount % 2 == 0)) || (kBit == 0 && (oneCount % 2 == 1)))
            {
                // If the current bit is incorrect, we increment the flip counter
                flips++;
            }
        }

        return flips;
    }
};

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int num = nums[0];
        int flips = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            num ^= nums[i];
        }
        num = num ^ k;
        while (num != 0)
        {
            flips++;

            num = num & (num - 1);
        }
        return flips;
    }
};