class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        // process first
        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while (!pq.empty()) {
            pair<int, pair<int, int>> top = pq.top();

            int diff = top.first;
            pair<int,int> coords = top.second;

            int x = coords.first;
            int y = coords.second;

            pq.pop();

            for (auto &dir : directions){
                
                int _x = x + dir[0];
                int _y = y + dir[1];

                if(isSafe(_x,_y)){
                    int maxi = max(diff,abs(heights[x][y] - heights[_x][_y]));

                    if(maxi < result[_x][_y]){
                        //update
                        result[_x][_y] = maxi;
                        //push
                        pq.push({maxi,{_x,_y}});
                    }
                }
            }
        }

        return result[m - 1][n - 1];
    }
};