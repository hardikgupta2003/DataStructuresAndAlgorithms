#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
public:
    unordered_map<T, list<pair<T,int>>> adjList;

    void addEdge(T u, T v,int wt, bool direction)
    {

        if (direction == 1)
        { // Graph is directed
            adjList[u].push_back({v,wt});
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
                cout <<"{ "<< nbr.first<< " : "<<nbr.second<<"}, ";
            }
            cout << " }";
            cout << endl;
        }
    }
};

int main()
{
    Graph<int> g;
    // directed
    g.addEdge(1, 2, 2, 1);
    g.addEdge(1, 3, 5, 1);
    g.addEdge(1, 4, 6, 1);
    g.addEdge(3, 4, 7, 1);
    g.printAdjList();


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