//gfg and leetcode

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    if(s.size() & 1) return -1;
    
    int count=0;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        
        if(ch=='{'){
            st.push(ch);
        }
        else{ // it's a closing bracket
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
            else{ // again push , may be stack could be empty or top element could be '}'
                st.push(ch);
                
            }
        }
    }
    
    //all valid parenthesis are removed , and now invalid remaining parenthesis to be solved 
    while(!st.empty()){
    char A=st.top(); 
    st.pop();
    char B=st.top(); 
    st.pop();
    //if both char are { , {
    //just one reversal
    if(A == B){
        count++;
    }
    else{
        count+=2;
    }
    }
    return count;
}