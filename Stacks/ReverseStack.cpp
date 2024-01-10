#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
   void insertAtBottom(stack<int> &St,int X){
     
      
      if(St.empty()){
          St.push(X);
          return ;
      }
      

      int temp =St.top();
      St.pop();
      
      insertAtBottom(St,X);
      
      St.push(temp);
      
      
      
    }
    void Reverse(stack<int> &St){
        if(St.empty()){
            return ;
        }
        
        int temp= St.top();
        St.pop();
        
        Reverse(St);
        
        insertAtBottom(St,temp);
    }
};

//{ Driver Code Starts.


int main(){
   
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }

// } Driver Code Ends