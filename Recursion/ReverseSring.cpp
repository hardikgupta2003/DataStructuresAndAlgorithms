//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    void solve(string &str,int s,int e){
        if(s>=e){
            return;
        }
        
            swap(str[s],str[e]);
        
        solve(str,s+1,e-1);
    }
    string reverseWord(string str)
    {
        int s=0;
        int e=str.length()-1;
        solve(str,s,e);
        return str;
        
        
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends