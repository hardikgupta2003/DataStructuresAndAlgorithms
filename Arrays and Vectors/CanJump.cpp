#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxReach = 0;
        int pos = 0;

        while (pos <= maxReach)
        {

            maxReach = max(maxReach, pos + nums[pos]);

            if (maxReach >= nums.size() - 1)
                return true;
            pos++;
        }
        return false;
    }
};

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxReach = 0; // The farthest index we can reach.

        for (int i = 0; i < nums.size(); i++)
        {
            // If we can't reach the current position, return false.
            if (i > maxReach)
                return false;

            // Update maxReach.
            maxReach = max(maxReach, i + nums[i]);

            // If maxReach is at or beyond the last index, return true.
            if (maxReach >= nums.size() - 1)
                return true;
        }

        return false; // In case we exit the loop without reaching the last index.
    }
};
