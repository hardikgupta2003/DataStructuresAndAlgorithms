#include <bits/stdc++.h>
using namespace std;



// sliding window
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int n = nums.size(); // Size of the input array

        unordered_set<int> st; // Set to store unique elements within the current window
        int i = 0, j = 0;      // Two pointers: i (left) and j (right) for the sliding window

        // Sliding window approach
        while (j < n)
        {
            // Step 1: Ensure the window size does not exceed k
            if (abs(i - j) > k)
            {
                st.erase(nums[i]); // Remove the element at the left of the window
                i++;               // Shrink the window from the left
            }

            // Check if the current element nums[j] is already in the set (meaning it appeared within the window)
            if (st.find(nums[j]) != st.end())
            {
                return true; // If found, return true (duplicate found within distance k)
            }

            // Otherwise, add the current element nums[j] to the set and expand the window
            st.insert(nums[j]);
            j++; // Move the right pointer to expand the window
        }

        // If no duplicates are found within distance k, return false
        return false;
    }
};

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(nums[i]) == mp.end())
            {
                mp[nums[i]] = {1, i};
            }
            else
            {
                if (abs((mp[nums[i]].second) - i) <= k)
                {
                    return true;
                }
                mp[nums[i]].second = i;
            }
        }
        return false;
    }
};


