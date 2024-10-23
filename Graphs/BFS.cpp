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
    void bfsTraversal(T src, unordered_map<T,bool>& vis){
        // adjList me data member already hai
        // visited

        // queue to track BFS
        queue<T> q;

        //initial start (src node push kro)
        q.push(src);
        vis[src] = true;

        while(!q.empty()){
            // node nikalo q.front se
            T frontNode = q.front();
            // print krwao
            cout<<frontNode<<" ";
            // pop kro
            q.pop();

            // front ke saare nbrs agar unvisited hai toh Queue me push krdo
            for(auto nbr : adjList[frontNode]){
                // nbr-> pair of char, int(wt).. so nbr.first is that char
                T nbrData = nbr.first;

                // unvisited hai ? toh push krdo aur mark it visited
                if(!vis[nbrData]){
                    q.push(nbrData);
                    vis[nbrData] = true;
                }
            }
        }
    }
};

int main()
{
    Graph<char> g;
    // directed
    g.addEdge('a', 'b', 5, 0);
    g.addEdge('a','c',10,0);
    g.addEdge('b', 'd', 20, 0);
    g.addEdge('c', 'e', 50, 0);
    g.addEdge('c', 'f', 20, 0);
    g.addEdge('e', 'f', 50, 0);
    g.printAdjList();

    // bfs
    unordered_map<char,bool> vis;
    for(char node='a';node<='f';node++){
        if(!vis[node]){
            g.bfsTraversal(node,vis);
        }
    }

    // g.addEdge(0, 1, 5, 1);
    // g.addEdge(1, 2, 3, 1);
    // g.addEdge(1, 3, 3, 1);
    // g.addEdge(2, 3, 3, 1);
    // g.addEdge(3, 4, 3, 1);
    // g.addEdge(4, 5, 3, 1);
    // g.addEdge(5, 3, 3, 1);
    // g.printAdjList();

    // undirected
    // g.addEdge(0, 1, 5, 0);
    // g.addEdge(1, 2, 3, 0);
    // g.addEdge(1, 3, 3, 0);
    // g.addEdge(2, 3, 3, 0);
    // g.addEdge(3, 4, 3, 0);
    // g.addEdge(4, 5, 3, 0);
    // g.addEdge(5, 3, 3, 0);
    // g.printAdjList();

    return 0;
}