#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adjList;  // Adjacency list representation of the graph


    void addEdge(T u, T v, bool direction)
    {

        if (direction == 1)
        { // Graph is directed
            adjList[u].push_back(v);
        }
        else
        { // graph is undirected
            adjList[u].push_back(v);
            adjList[v].push_back(u);
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
                cout << nbr << ",";
            }
            cout << " }";
            cout << endl;
        }
    }
    bool checkCycleUndirectedBFS(int src){
        queue<int> q;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;

        // initial state
        q.push(src);
        parent[src] = -1;
        visited[src] = true;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto &nbr: adjList[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;

                }
                else if(visited[nbr] == true && nbr != parent[frontNode]){
                    //cycle present
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(2, 5, 0);

    // bfs
    // g.printAdjList();
    int src = 0;
    bool iscyclic = g.checkCycleUndirectedBFS(src);
    if(iscyclic){
        cout << "Graph contains cycle" << endl;
    }
    else{
        cout<<"Graph does not contains cycle "<<endl;
    }


    





    return 0;
}

// gfg
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool checkCycleUndirectedBFS(int src, unordered_map<int, bool> &visited, vector<vector<int>> &adj)
    {
        queue<int> q;
        unordered_map<int, int> parent;

        // initial state
        q.push(src);
        parent[src] = -1;
        visited[src] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto &nbr : adj[frontNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                else if (visited[nbr] == true && nbr != parent[frontNode])
                {
                    // cycle present
                    return true;
                }
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
                bool ans = checkCycleUndirectedBFS(i, visited, adj);
                if (ans)
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