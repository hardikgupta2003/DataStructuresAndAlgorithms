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