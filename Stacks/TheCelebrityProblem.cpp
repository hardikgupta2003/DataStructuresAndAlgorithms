//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()!=1){
            
            int A=st.top();
            st.pop();
            int B=st.top(); 
            st.pop();
            
            if(M[A][B]){
                //A is not celebrity
                // discard A
                // push B
                st.push(B);
            }
            else{
                // B is not a celebrity
                //discard A
                // push A
                st.push(A);
            }
        }
        int celeb = st.top();
        st.pop();
        //celeb can be a potential candidate to be a celebrity
          int zeroCount=0;
        
        for(int i=0;i<n;i++){
            if(M[celeb][i]==0){
                zeroCount++;
            }
        }
            if(zeroCount!=n){
                return -1;
            }
            int oneCount=0;
              for(int i=0;i<n;i++){
            if(M[i][celeb]==1){
                oneCount++;
            }
              }
              if(oneCount!=n-1){
                return -1;
            }
       
        return celeb;
       
    }
};

//{ Driver Code Starts.

int main()
{
   
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    
}

// } Driver Code Ends