#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; i++)
        {
            sort(grid[i].begin(), grid[i].end());
        }
        int ans = 0;
        while (col > 0)
        {
            int maxDelete = INT_MIN;
            for (int i = 0; i < row; i++)
            {
                int element = grid[i][col - 1];
                maxDelete = max(maxDelete, element);
                grid[i].pop_back();
            }
            ans += maxDelete;
            col--;
        }

        return ans;
    }
};