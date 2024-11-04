#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        if (direction == 0)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else
        {
            adjList[u].push_back(v);
        }
    }
    void PrintEdge()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void shortestPathBfs(int src,int dest){
        queue<int> q;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;

        // initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto nbr:adjList[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
            }
        }

        // parent array ready hoga
        vector<int> ans;
        while(dest != -1){
            ans.push_back(dest);
            dest = parent[dest];

        }
        reverse(ans.begin(),ans.end());
        for(auto i:ans){
            cout<<i<<" ";
        }
    }

};
int main()
{
    Graph g;
    g.addEdge(0, 4, 0);
    g.addEdge(4, 1, 0);
    g.addEdge(1, 5, 0);
    g.addEdge(0, 3, 0);
    g.addEdge(3, 5, 0);
    g.addEdge(0, 6, 0);
    g.addEdge(6, 2, 0);
    g.addEdge(2, 5, 0);
    // g.PrintEdge();

    g.shortestPathBfs(0,5);

        return 0;
}