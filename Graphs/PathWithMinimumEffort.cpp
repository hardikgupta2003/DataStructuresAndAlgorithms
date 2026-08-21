#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <functional>
#include <utility>

using namespace std;

class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> directions = {
        {0, -1}, {-1, 0}, {0, 1}, {1, 0}
    };

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        // result[i][j] = minimum effort required to reach (i,j)
        vector<vector<int>> result(
            m, vector<int>(n, INT_MAX)
        );

        // {effort, {row, col}}
        priority_queue<P, vector<P>, greater<P>> pq;

        result[0][0] = 0;
        pq.push({0, {0, 0}});

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m &&
                   y >= 0 && y < n;
        };

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int diff = top.first;
            int x = top.second.first;
            int y = top.second.second;

            // Check all 4 directions
            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (!isSafe(nx, ny))
                    continue;

                // Effort of current path
                int newEffort = max(
                    diff,
                    abs(heights[x][y] - heights[nx][ny])
                );

                // Found a better path
                if (newEffort < result[nx][ny]) {
                    result[nx][ny] = newEffort;

                    pq.push({
                        newEffort,
                        {nx, ny}
                    });
                }
            }
        }

        return result[m - 1][n - 1];
    }
};


// Driver Code
int main() {
    Solution obj;

    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    cout << "Minimum Effort = "
         << obj.minimumEffortPath(heights)
         << endl;

    return 0;
}