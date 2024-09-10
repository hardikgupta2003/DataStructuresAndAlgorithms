#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(),
             [](const std::vector<int> &a, const std::vector<int> &b)
             {
                 return a[1] < b[1];
             });
        int ans = 0;
        int currMin = INT_MIN;
        for (int i = 0; i < pairs.size(); i++)
        {
            vector<int> pair = pairs[i];
            if (pair[0] > currMin)
            {
                ans++;
                currMin = pair[1];
            }
        }
        return ans;
    }
};