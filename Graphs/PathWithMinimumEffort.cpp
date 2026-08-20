#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Min-heap pair structure: {effort, {row, col}}
    typedef pair<int, pair<int, int>> P;
    
    // 4-directional moves: Left, Up, Right, Down
    vector<vector<int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        // result[i][j] stores the minimum effort required to reach cell (i, j)
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        // Min-heap to always process the path with the minimum effort first
        priority_queue<P, vector<P>, greater<P>> pq;

        // Lambda helper to check if coordinates are within grid boundaries
        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        // Initialize with the starting cell (0, 0)
        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while (!pq.empty()) {
            pair<int, pair<int, int>> top = pq.top();

            int diff = top.first; // Current maximum effort on this path
            pair<int,int> coords = top.second;

            int x = coords.first;
            int y = coords.second;

            pq.pop();

            // Check all 4-directional neighbors
            for (auto &dir : directions){
                int _x = x + dir[0];
                int _y = y + dir[1];

                if(isSafe(_x,_y)){
                    // Effort to reach neighbor is the max of current path effort and the height difference
                    int maxi = max(diff, abs(heights[x][y] - heights[_x][_y]));

                    // If we found a path to neighbor with less effort, update and push to queue
                    if(maxi < result[_x][_y]){
                        result[_x][_y] = maxi;
                        pq.push({maxi, {_x, _y}});
                    }
                }
            }
        }

        // Return the minimum effort to reach the bottom-right cell
        return result[m - 1][n - 1];
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard grid with alternative paths
    vector<vector<int>> heights1 = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };
    cout << "Test Case 1:\n";
    cout << "Input Grid:\n";
    for (auto& row : heights1) {
        for (int val : row) cout << val << " ";
        cout << "\n";
    }
    cout << "Output:   " << sol.minimumEffortPath(heights1) << "\n";
    cout << "Expected: 2\n\n";

    // Test Case 2: Uniform grid (expected effort is 0)
    vector<vector<int>> heights2 = {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    };
    cout << "Test Case 2:\n";
    cout << "Input Grid:\n";
    for (auto& row : heights2) {
        for (int val : row) cout << val << " ";
        cout << "\n";
    }
    cout << "Output:   " << sol.minimumEffortPath(heights2) << "\n";
    cout << "Expected: 0\n\n";

    // Test Case 3: Grid with high variation path
    vector<vector<int>> heights3 = {
        {1, 2, 3},
        {3, 8, 4},
        {5, 3, 5}
    };
    cout << "Test Case 3:\n";
    cout << "Input Grid:\n";
    for (auto& row : heights3) {
        for (int val : row) cout << val << " ";
        cout << "\n";
    }
    cout << "Output:   " << sol.minimumEffortPath(heights3) << "\n";
    cout << "Expected: 1\n\n";

    return 0;
}