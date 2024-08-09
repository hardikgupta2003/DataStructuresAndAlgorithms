#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2 - count])
            {
                count++;
            }
            else
            {
                nums[i - count] = nums[i];
            }
        }
        return n - count;
    }
};

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n; // Edge case: If the array has 2 or fewer elements, it's already valid.

        int index = 2; // Start from the 3rd element.
        for (int i = 2; i < n; i++)
        {
            // Compare the current element with the element two places before it.
            if (nums[i] != nums[index - 2])
            {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};