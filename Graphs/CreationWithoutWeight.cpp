#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    public:
    unordered_map<T,list<T>> adjList;


    void addEdge(T u,T v,bool direction){
        
        if(direction == 1){ // Graph is directed
            adjList[u].push_back(v);
        }
        else{ // graph is undirected
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        cout<<"Printing Adj list: "<<endl;
        for(auto &i:adjList){
            cout<<i.first<<" -> { ";
            for(auto &nbr:i.second){
                cout<<nbr<<",";
            }
            cout<<" }";
            cout<<endl;
        }
    }
};

int main(){
    Graph<int> g;
    // directed
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(1,3,1);
    // g.addEdge(2,3,1);
    // g.addEdge(3,4,1);
    // g.addEdge(4,5,1);
    // g.addEdge(5,3,1);
    // g.printAdjList();

    // undirected
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(4,5,0);
    g.addEdge(5,3,0);
    g.printAdjList();



    return 0;
}