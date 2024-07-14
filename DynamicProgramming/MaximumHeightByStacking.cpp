#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkCuboid(vector<int> &prev, vector<int> &curr)
    {
        // curr -> larger cuboid
        // prev -> smaller cuboid

        if (prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int solveByTabulation(vector<vector<int>> &cuboids)
    {
        int n = cuboids.size();
        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for (int currIndex = n - 1; currIndex >= 0; currIndex--)
        {
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--)
            {
                int include = 0;
                if (prevIndex == -1 || checkCuboid(cuboids[prevIndex], cuboids[currIndex]))
                {
                    int heightToAdd = cuboids[currIndex][2];
                    include = heightToAdd + next[currIndex + 1];
                }
                int exclude = 0 + next[prevIndex + 1];
                curr[prevIndex + 1] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }
    int maxHeight(vector<vector<int>> &cuboids)
    {

        for (auto &cuboid : cuboids)
        {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());
        return solveByTabulation(cuboids);
    }
};