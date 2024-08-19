#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPaths(vector<vector<int>> &grid, int i, int j, int walkOver, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1)
        {
            return 0;
        }
        if (grid[i][j] == 2)
        {
            if (walkOver == -1)
            {
                return 1;
            }

            return 0;
        }

        grid[i][j] = -1;
        walkOver--;

        int totalPath = findPaths(grid, i + 1, j, walkOver, m, n) +
                        findPaths(grid, i - 1, j, walkOver, m, n) +
                        findPaths(grid, i, j + 1, walkOver, m, n) +
                        findPaths(grid, i, j - 1, walkOver, m, n);

        grid[i][j] = 0;
        walkOver++;

        return totalPath;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int Istart = 0;
        int Jstart = 0;
        int walkOver = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    Istart = i;
                    Jstart = j;
                }
                else if (grid[i][j] == 0)
                {
                    walkOver++;
                }
            }
        }
        return findPaths(grid, Istart, Jstart, walkOver, m, n);
    }
};