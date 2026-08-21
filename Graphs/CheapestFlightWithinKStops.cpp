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
    // {cost, node, flights}
    typedef tuple<int, int, int> T;

    int findCheapestPrice(
        int n,
        vector<vector<int>>& flights,
        int src,
        int dst,
        int k
    ) {
        // Adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];

            adj[u].push_back({v, price});
        }

        // Min heap: minimum cost comes first
        priority_queue<T, vector<T>, greater<T>> pq;

        // result[node][flights]
        vector<vector<int>> result(
            n, vector<int>(k + 2, INT_MAX)
        );

        // Starting point
        result[src][0] = 0;
        pq.push({0, src, 0});

        while (!pq.empty()) {

            auto [cost, u, stops] = pq.top();
            pq.pop();

            // Cheapest valid path found
            if (u == dst) {
                return cost;
            }

            // Already used maximum allowed flights
            if (stops == k + 1) {
                continue;
            }

            // Explore neighbours
            for (auto [v, price] : adj[u]) {

                int newCost = cost + price;
                int newStops = stops + 1;

                // Better cost for this node with this
                // exact number of flights
                if (newCost < result[v][newStops]) {

                    result[v][newStops] = newCost;

                    pq.push({
                        newCost,
                        v,
                        newStops
                    });
                }
            }
        }

        return -1;
    }
};


// Driver Code
int main() {

    Solution obj;

    int n = 4;

    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };

    int src = 0;
    int dst = 3;
    int k = 1;

    int answer = obj.findCheapestPrice(
        n, flights, src, dst, k
    );

    cout << "Cheapest Price = " << answer << endl;

    return 0;
}