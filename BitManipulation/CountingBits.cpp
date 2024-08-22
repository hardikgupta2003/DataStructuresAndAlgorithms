#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i = 0; i <= n; i++)
        {
            int m = i;
            int count = 0;
            for (int j = 0; j < 32; j++)
            {
                if ((m & 1) == 1)
                {
                    count++;
                }
                m = m >> 1;
            }
            ans.push_back(count);
        }
        return ans;
    }
};