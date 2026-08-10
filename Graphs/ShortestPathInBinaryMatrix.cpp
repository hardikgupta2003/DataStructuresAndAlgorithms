#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

class Solution {
public:
    // {distance, {row, col}} — ordered by distance so pq.top() is always the closest unvisited cell
    typedef pair<int, pair<int, int>> P;

    // 8 possible moves (all neighbors, since diagonal moves are allowed)
    vector<vector<int>> directions{{0, -1}, {-1, -1}, {-1, 0}, {-1, 1},
                                   {0, 1},  {1, 1},   {1, 0},  {1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // no grid, or start cell blocked -> no path possible
        if (n == 0 || grid[0][0] != 0)
            return -1;

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < n;
        };
        // min-heap on distance -> Dijkstra (works even though edge weights are all 1;
        // a plain BFS would also work here, but this generalizes if weights ever differ)
        priority_queue<P, vector<P>, greater<P>> pq;

        // result[x][y] = shortest number of steps from (0,0) to (x,y)
        vector<vector<int>> result(n, vector<int>(n, INT_MAX));

        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            pair<int, pair<int, int>> top = pq.top();

            int d = top.first;
            pair<int, int> cord = top.second;
            int x = cord.first;
            int y = cord.second;

            pq.pop();

            for (auto& dir : directions) {

                int _x = x + dir[0];
                int _y = y + dir[1];

                int dist = 1;

                // relax neighbor only if it's in bounds, open (0), and gives a shorter path
                if (isSafe(_x, _y) && grid[_x][_y] == 0 &&
                    d + dist < result[_x][_y]) {
                    result[_x][_y] = d + dist;
                    pq.push({d + dist, {_x, _y}});
                }
            }
        }
        // +1 to convert "steps between cells" into "count of cells visited" (path length)
        return result[n - 1][n - 1] == INT_MAX ? -1 : result[n - 1][n - 1] + 1;
    }
};

int main() {
    Solution sol;

    // Test 1: simple 2x2 open grid -> path exists, length 2
    vector<vector<int>> grid1 = {{0, 1}, {1, 0}};
    cout << "Test 1: " << sol.shortestPathBinaryMatrix(grid1) << " (expected 2)\n";

    // Test 2: 3x3 grid with a blocked middle -> diagonal path around it, length 4
    vector<vector<int>> grid2 = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << "Test 2: " << sol.shortestPathBinaryMatrix(grid2) << " (expected 4)\n";

    // Test 3: start cell itself blocked -> no path
    vector<vector<int>> grid3 = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << "Test 3: " << sol.shortestPathBinaryMatrix(grid3) << " (expected -1)\n";

    return 0;
}