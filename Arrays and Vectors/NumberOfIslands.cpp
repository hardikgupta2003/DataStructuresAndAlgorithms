#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void numberOfIslands(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
        {
            return;
        }

        // if not marked ,make it marked
        grid[i][j] = '0';

        numberOfIslands(grid, i + 1, j);
        numberOfIslands(grid, i, j + 1);
        numberOfIslands(grid, i - 1, j);
        numberOfIslands(grid, i, j - 1);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    numberOfIslands(grid, i, j);
                    count += 1;
                }
            }
        }
        return count;
    }
};