
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> st;
        int rem= q.size()-k;
        
        while(k--){
           int temp=q.front();
           q.pop();
           
           st.push(temp);
           
        }
        while(!st.empty()){
            int top = st.top();
            st.pop();
            q.push(top);
        }
        while(rem--){
            int temp= q.front();
            q.pop();
            q.push(temp);
        }
        
        return q;
            
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends