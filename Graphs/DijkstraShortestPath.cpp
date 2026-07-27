#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
public:
    unordered_map<T, list<pair<T, int>>> adjList;

    void addEdge(T u, T v, int wt, bool direction)
    {

        if (direction == 1)
        { // Graph is directed
            adjList[u].push_back({v, wt});
        }
        else
        { // graph is undirected
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList()
    {
        cout << "Printing Adj list: " << endl;
        for (auto &i : adjList)
        {
            cout << i.first << " -> { ";
            for (auto &nbr : i.second)
            {
                cout << "{ " << nbr.first << " : " << nbr.second << "}, ";
            }
            cout << " }";
            cout << endl;
        }
    }

    void dijkstraShortestPath(int n, int src, int dest)
    {
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> st;

        // initial state (0,src)
        st.insert({0, src});
        dist[src] = 0;

        // distance updation logic
        while (!st.empty())
        {
            auto topElement = st.begin();
            pair<int, int> topPair = *topElement;
            int topDist = topPair.first;
            int topNode = topPair.second;

            // remove the top Node
            st.erase(st.begin());

            // update distance of nbr
            for (pair<int, int> nbrPair : adjList[topNode])
            {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                if (topDist + nbrDist < dist[nbrNode])
                {

                    // found a new shorter distance
                    // now update:
                    // set ki entry
                    auto prevEntry = st.find({dist[nbrNode], nbrNode});
                    if (prevEntry != st.end())
                    {
                        st.erase(prevEntry);
                    }
                    // dist ka array
                    dist[nbrNode] = topDist + nbrDist;
                    st.insert({dist[nbrNode],nbrNode});
                }
            }
        }
        cout << "shortest distance from : " << src << " Node to " << dest << " Node : " << dist[dest] << endl;
    }
};

int main()
{
    Graph<int> g;

    g.addEdge(5, 6, 9, 0);
    g.addEdge(5, 4, 6, 0);
    g.addEdge(6, 1, 14, 0);
    g.addEdge(6, 3, 2, 0);
    g.addEdge(2, 3, 10, 0);
    g.addEdge(4, 3, 11, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(2, 1, 7, 0);
    // g.printAdjList();

    g.dijkstraShortestPath(6,6,4);

    return 0;
}

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {

        // Min Heap -> {distance, node}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        // Stores the shortest distance from source to every node
        vector<int> result(V, INT_MAX);

        // Adjacency List -> {neighbor, weight}
        vector<vector<pair<int, int>>> adj(V);

        // Convert edge list into adjacency list
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // Since graph is undirected
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Distance from source to itself is 0
        result[src] = 0;

        // Push source node into min heap
        pq.push({0, src});

        while (!pq.empty())
        {

            // Get node having minimum distance
            pair<int, int> top = pq.top();
            pq.pop();

            int wt = top.first; // Current shortest distance
            int node = top.second;

            // Traverse all adjacent nodes
            for (auto &vec : adj[node])
            {

                int adjNode = vec.first; // Neighbor node
                int d = vec.second;      // Edge weight

                // Relax the edge if a shorter path is found
                if (wt + d < result[adjNode])
                {
                    result[adjNode] = wt + d;

                    // Push updated distance into heap
                    pq.push({result[adjNode], adjNode});
                }
            }
        }

        return result;
    }
};

//using set

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        // Stores {distance, node} in sorted order by distance
        set<pair<int, int>> st;

        // Stores the shortest distance from source to every node
        vector<int> result(V, INT_MAX);

        // Adjacency List -> {neighbor, weight}
        vector<vector<pair<int, int>>> adj(V);

        // Convert edge list into adjacency list
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // Since the graph is undirected
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Distance from source to itself is 0
        result[src] = 0;

        // Insert source node with distance 0
        st.insert({0, src});

        while (!st.empty()) {

            // Extract the node having the minimum distance
            pair<int, int> top = *st.begin();
            st.erase(top);

            int wt = top.first;      // Current shortest distance
            int node = top.second;   // Current node

            // Traverse all adjacent nodes
            for (auto &vec : adj[node]) {

                int adjNode = vec.first;   // Neighbor node
                int d = vec.second;        // Edge weight

                // Relax the edge if a shorter path is found
                if (wt + d < result[adjNode]) {

                    // Remove the old entry if it exists in the set
                    if (result[adjNode] != INT_MAX) {
                        st.erase({result[adjNode], adjNode});
                    }

                    // Update the shortest distance
                    result[adjNode] = wt + d;

                    // Insert the updated distance
                    st.insert({result[adjNode], adjNode});
                }
            }
        }

        return result;
    }
};