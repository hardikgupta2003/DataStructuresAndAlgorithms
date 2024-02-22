//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
       stack<int> st;
       while(!q.empty()){
           int x= q.front();
           q.pop();
           st.push(x);
       }
       while(!st.empty()){
           int top = st.top();
           st.pop();
           q.push(top);
       }
       return q;
    }

     void solve(queue<int> &q){
        if(q.empty()){
            return;
        }
        int temp=q.front();
        q.pop();
        
        //calling recursion function
        solve(q);
        q.push(temp);
        
    }
    queue<int> rev(queue<int> q)
    {
        solve(q);
        return q;
       
    }
    
};


//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends