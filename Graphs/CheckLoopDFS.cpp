//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool checkCycleUndirectedDFS(int src, unordered_map<int, bool> &visited, int parent, vector<vector<int>> &adj)
    {
        visited[src] = true;

        for (auto nbr : adj[src])
        {
            if (nbr == parent)
            {
                continue;
            }
            if (!visited[nbr])
            {
                bool ans = checkCycleUndirectedDFS(nbr, visited, src, adj);
                if (ans == true)
                {
                    return true;
                }
            }
            else if (visited[nbr] == 1)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>> adj)
    {
        // Code here
        int V = adj.size();
        unordered_map<int, bool> visited;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                int parent = -1;
                bool ans = checkCycleUndirectedDFS(i, visited, parent, adj);
                if (ans == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends

// 5 5 0 1 1 2 1 4 2 3 3 4