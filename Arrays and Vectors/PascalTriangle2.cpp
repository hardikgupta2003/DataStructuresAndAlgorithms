#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> temp(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(temp);
        }

        return ans;
    }
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> pt = generate(rowIndex + 1);
        vector<int> ans;
        int size = pt[rowIndex].size();
        for (int i = 0; i < size; i++)
        {
            ans.push_back(pt[rowIndex][i]);
        }
        return ans;
    }
};