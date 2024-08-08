#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(
            n, vector<int>(n)); // Create the matrix filled with zeros
        int count = 1;          // Start counting from 1

        int startingRow = 0;
        int endingRow = n - 1;
        int startingCol = 0;
        int endingCol = n - 1;

        while (startingRow <= endingRow && startingCol <= endingCol)
        {
            // Traverse from left to right
            for (int i = startingCol; i <= endingCol; i++)
            {
                ans[startingRow][i] = count++;
            }
            startingRow++;

            // Traverse from top to bottom
            for (int i = startingRow; i <= endingRow; i++)
            {
                ans[i][endingCol] = count++;
            }
            endingCol--;

            // Traverse from right to left
            if (startingRow <= endingRow)
            {
                for (int i = endingCol; i >= startingCol; i--)
                {
                    ans[endingRow][i] = count++;
                }
                endingRow--;
            }

            // Traverse from bottom to top
            if (startingCol <= endingCol)
            {
                for (int i = endingRow; i >= startingRow; i--)
                {
                    ans[i][startingCol] = count++;
                }
                startingCol++;
            }
        }

        return ans;
    }
};
