#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int mini = arrays[0].front();
        int maxi = arrays[0].back();

        int result = 0;
        int n = arrays.size();
        for (int i = 1; i < n; i++)
        {
            int currMini = arrays[i].front();
            int currMaxi = arrays[i].back();

            result = max(result, max(abs(currMini - maxi), abs(currMaxi - mini)));

            maxi = max(maxi, currMaxi);
            mini = min(mini, currMini);
        }
        return result;
    }
};

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int mini = INT_MAX; // To track the minimum value
        int maxi = INT_MIN; // To track the maximum value
        int minIndex = -1;  // To track the index of the array containing mini
        int maxIndex = -1;  // To track the index of the array containing maxi
        int n = arrays.size();

        // First pass: Find the global minimum and maximum with their indices
        for (int i = 0; i < n; i++)
        {
            if (arrays[i][0] < mini)
            {
                mini = arrays[i][0];
                minIndex = i;
            }
            if (arrays[i].back() > maxi)
            {
                maxi = arrays[i].back();
                maxIndex = i;
            }
        }

        // Second pass: Calculate max distance considering non-overlapping arrays
        int maxDist = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != minIndex)
            {
                maxDist = max(maxDist, arrays[i].back() - mini);
            }
            if (i != maxIndex)
            {
                maxDist = max(maxDist, maxi - arrays[i][0]);
            }
        }

        return maxDist;
    }
};