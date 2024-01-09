//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
     void solve(stack <int> &st,int pos){
        //base case
        if(pos==1){
            st.pop();
            return;
        }
        
        pos--;
        int temp=st.top();
        st.pop();
        
        //recursion
        solve(st,pos);
        
        //push
        st.push(temp);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int pos=0;
        
      
            pos=(sizeOfStack/2)+1;
        
    
         solve(s,pos);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends