#include <iostream>
#include <vector>
using namespace std;

void wavePrint(vector<vector<int>> v){
    int m=v.size();
    cout<<"m: "<<m<<endl;
    int n=v[0].size();
    cout<<"n: "<<n<<endl;

    for(int i=0;i<n;i++){
        //for even
        if((i&1)==0){
            for(int j=0;j<m;j++){
            cout<<v[j][i]<<" ";
        }
        }
        // for odd
        else{
           for(int j=m-1;j>=0;j--){
            cout<<v[j][i]<<" ";
        } 
        }
        
    }

    
}
int main()
{

    vector<vector<int>> v{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    wavePrint(v);

}