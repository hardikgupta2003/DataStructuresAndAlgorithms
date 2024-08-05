#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int n;                   // Store the size of the input array
    vector<vector<int>> ans; // To store all the permutations
    unordered_set<int> set;  // To keep track of elements already included in the current permutation

    // Helper function for backtracking
    void backtrack(vector<int> &nums, vector<int> &temp)
    {
        // If the current permutation is of the same length as the original array, add it to the results
        if (temp.size() == n)
        {
            ans.push_back(temp);
            return;
        }

        // Iterate through each element in the array
        for (int i = 0; i < nums.size(); i++)
        {
            // If the element is not already included in the current permutation
            if (set.find(nums[i]) == set.end())
            {
                temp.push_back(nums[i]); // Add element to the current permutation
                set.insert(nums[i]);     // Mark element as used

                backtrack(nums, temp); // Recurse to add the next element

                // Backtrack: remove the last added element and mark it as unused
                temp.pop_back();
                set.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        n = nums.size();
        vector<int> temp;      // Temporary vector to build permutations
        backtrack(nums, temp); // Start the backtracking process
        return ans;
    }
};

// approach 2

class Solution {
public:
    int n; // Store the size of the input array
    vector<vector<int>> ans; // To store all the permutations

    // Helper function for backtracking
    void backtrack(vector<int>& nums, int index) {
        // If the current permutation is of the same length as the original array, add it to the results
        if (index == n) {
            ans.push_back(nums);
            return;
        }

        // Iterate through each element starting from the current index
        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]); // Swap the current element with the element at the current index
            
            backtrack(nums, index + 1); // Recurse to add the next element

            swap(nums[i], nums[index]); // Backtrack: swap back to restore the original array
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size(); 
        backtrack(nums, 0); // Start the backtracking process
        return ans;
    }
};
