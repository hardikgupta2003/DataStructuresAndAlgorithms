class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {

        // Adjacency List:
        // node -> {neighbor, edgeWeight}
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto &edge : times)
        {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            // Directed edge
            adj[u].push_back({v, weight});
        }

        // dist[i] = Shortest distance from source (k) to node (i + 1)
        vector<int> dist(n + 1, INT_MAX);

        // Min Heap -> {currentDistance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            minHeap;

        dist[k] = 0;
        minHeap.push({0, k});

        while (!minHeap.empty())
        {

            auto [currentDistance, node] = minHeap.top();
            minHeap.pop();

            // Skip outdated entries
            if (currentDistance > dist[node])
                continue;

            // Traverse all neighbors
            for (auto &[neighbor, edgeWeight] : adj[node])
            {

                // Relax the edge
                if (currentDistance + edgeWeight < dist[neighbor])
                {
                    dist[neighbor] = currentDistance + edgeWeight;
                    minHeap.push({dist[neighbor], neighbor});
                }
            }
        }

        // Find the maximum shortest distance
        int maxTime = INT_MIN;

        for (int i = 1; i < dist.size(); i++)
        {
            int distance = dist[i];
            if (distance == INT_MAX)
                return -1; // Some node is unreachable

            maxTime = max(maxTime, distance);
        }

        return maxTime;
    }
};