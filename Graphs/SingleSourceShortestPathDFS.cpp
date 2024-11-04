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

    void topoOrderDFS(int src,stack<int> &topo,unordered_map<int,bool> &visited){
        visited[src] = true;

        for(auto nbrPair : adjList[src]){
            int nbrNode = nbrPair.first;  
            if(!visited[nbrNode]){
                topoOrderDFS(nbrNode,topo,visited);
            }
        }
        topo.push(src);
    }

    void shortestPathDFS(stack<int>&topoOrder,int n){
        vector<int> dist(n,INT_MAX);

        //initally , maintain the src
        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;


        // update nbr distance for this src Node
        for(auto nbrPair : adjList[src]){
            int nbrNode = nbrPair.first;
            int nbrDist =  nbrPair.second;
            if(dist[src] + nbrDist < dist[nbrNode]){
                dist[nbrNode] = dist[src] + nbrDist;
            } 
        }


        // apply the same above concept for all the remaining node
        while(!topoOrder.empty()){
            int src = topoOrder.top();
            topoOrder.pop();
            

            // update nbr distance for this src Node
            for (auto nbrPair : adjList[src])
            {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                if (dist[src] + nbrDist < dist[nbrNode])
                {
                    dist[nbrNode] = dist[src] + nbrDist;
                }
            }
        }

        // now distance array is ready
        cout<<"printing the distance array : "<<endl;
        for(auto i:dist){
            cout<<i<<" ";
        }
    }
};

int main()
{
    Graph<int> g;

    g.addEdge(0, 1, 5, 1);
    g.addEdge(1, 3, 3, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(2, 4, 6, 1);
    g.addEdge(2, 3, 5, 1);
    g.addEdge(2, 1, 2, 1);
    g.addEdge(4, 3, 1, 1);
    // g.printAdjList();

    int src = 0;
    int n = 5;
    stack<int> topoOrder;
    unordered_map<int,bool> visited;
    g.topoOrderDFS(src,topoOrder,visited);
    // cout << "Topological Order: ";
    // while(!topoOrder.empty()){
    //     cout << topoOrder.top() << " ";
    //     topoOrder.pop();
    // }
    g.shortestPathDFS(topoOrder, n);

    return 0;
}