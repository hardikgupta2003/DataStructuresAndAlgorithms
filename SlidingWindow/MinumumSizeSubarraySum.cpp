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

// better
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size(); // Size of the array
        int i = 0, j = 0;    // i: start of the window, j: end of the window
        int ans = INT_MAX;   // Initialize answer as maximum possible value
        int sum = 0;         // Current sum of the window

        while (j < n)
        {
            sum += nums[j]; // Add nums[j] to the current sum

            // Shrink the window from the left while the sum is >= target
            while (sum >= target)
            {
                ans = min(ans, j - i + 1); // Update the minimum length
                sum -= nums[i];            // Remove nums[i] from the sum
                i++;                       // Move the start of the window forward
            }

            j++; // Expand the window by moving the end forward
        }

        // If ans is still INT_MAX, no valid subarray was found
        return ans == INT_MAX ? 0 : ans;
    }
};
