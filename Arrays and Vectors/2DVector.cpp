#include <iostream>
#include <vector>
using namespace std;

int main(){

    
    vector<vector<int>> v(5,vector<int>(5,3));
    int n=v.size();
     cout<<"printing vector : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}