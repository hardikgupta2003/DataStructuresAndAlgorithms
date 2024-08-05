#include "bits/stdc++.h"
using namespace std;


class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return {};

        vector<vector<int>> ans;
        // Sort intervals based on the start time
        sort(intervals.begin(), intervals.end());

        // Initialize the first interval
        vector<int> current = intervals[0];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (current[1] >= intervals[i][0])
            {
                // If the current interval overlaps with the next interval, merge them
                current[1] = max(current[1], intervals[i][1]);
            }
            else
            {
                // If the current interval does not overlap, push the current interval and update it
                ans.push_back(current);
                current = intervals[i];
            }
        }

        // Push the last interval
        ans.push_back(current);

        return ans;
    }
};