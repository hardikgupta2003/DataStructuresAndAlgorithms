#include<iostream>
#include<vector>

using namespace std;


void print(vector<int> v){
    int n=v.size();
    for (int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    
    vector<int> v;

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        v.push_back(d);
    }

    print(v);
    v.clear();

    v.push_back(45);
    print(v);

    return 0;
}