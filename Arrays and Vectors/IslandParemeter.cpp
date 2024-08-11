#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int perimeter;

public:
    void DFS(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
        {
            perimeter++;
            return;
        }
        if (grid[i][j] == -1)
        {
            return;
        }
        // if not marked ,make it marked
        grid[i][j] = -1;

        DFS(grid, i + 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i - 1, j);
        DFS(grid, i, j - 1);
    }
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        perimeter = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    DFS(grid, i, j);
                    return perimeter;
                }
            }
        }
        return -1;
    }
};