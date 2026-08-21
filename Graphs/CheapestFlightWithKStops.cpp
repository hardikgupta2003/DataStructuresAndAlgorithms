class Solution {
public:
    // cost, node, stops
    typedef tuple<int, int, int> T;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int d = flight[2];

            adj[u].push_back({v, d});
        }

        priority_queue<T, vector<T>, greater<T>> pq;

        vector<vector<int>> result(n, vector<int>(k + 2, INT_MAX));

        result[src][0] = 0;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();

            if (u == dst) {
                return cost;
            }

            if (stops == k + 1) {
                continue;
            }
            for (auto [v, price] : adj[u]) {

                int newCost = cost + price;
                int newStops = stops + 1;

                if (newCost < result[v][newStops]) {
                    result[v][newStops] = newCost;
                    pq.push({newCost, v, newStops});
                }
            }
        }
        return -1;
    }
};