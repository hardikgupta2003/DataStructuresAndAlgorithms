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