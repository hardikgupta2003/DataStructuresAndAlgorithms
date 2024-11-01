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

    void topoSortBFS(int n)
    {
      queue<int> q;
      map<int,int> indegree;
      // initialize kardi indegree sabki
      for(auto i:adjList){
        for(auto j:i.second){
            indegree[j]++;
        }
      }
      
      // push all zero indegree wali node into Queue
      for(int node=0;node<n;node++){
        if(indegree[node]==0){
            q.push(node);
        }
      }

      //BFS chalate hai
      while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        cout<<frontNode<<", ";

        for(auto nbr:adjList[frontNode]){
            indegree[nbr]--;

            //check for zero
            if(indegree[nbr]==0){
                q.push(nbr);  
            }
        }
      }
    }
};
int main()
{
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(5, 7, 1);
    // g.PrintEdge();
    map<int, bool> visited;
    stack<int> st;
    g.topoSortBFS(8);
    

    return 0;
}