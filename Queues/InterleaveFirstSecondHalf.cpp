//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int> first;
        queue<int> second;
        
        int n= q.size()/2;
        
        while(n--){
            int temp=q.front();
            q.pop();
            first.push(temp);
        }
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            second.push(temp);
        }
        vector<int> ans;
        while(!first.empty() && !second.empty()){
           int f = first.front();
           first.pop();
           ans.push_back(f);
           int s = second.front();
           second.pop();
           ans.push_back(s);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends