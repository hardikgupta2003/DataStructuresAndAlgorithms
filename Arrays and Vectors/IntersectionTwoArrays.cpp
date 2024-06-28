// leetcode easy
// intersection of two arrays
// https://leetcode.com/problems/intersection-of-two-arrays-ii/
// code
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        // Use unordered_set for quick lookup and to store unique results
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> resultSet;

        // Check each element of nums2 in set1
        for (int num : nums2)
        {
            if (set1.find(num) != set1.end())
            {
                resultSet.insert(num);
            }
        }

        // Convert resultSet to a vector
        vector<int> result(resultSet.begin(), resultSet.end());
        return result;
    }
};
