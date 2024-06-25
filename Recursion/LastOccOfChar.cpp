//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void solve(string &s, char p, int index, int &ans)
    {
        if (index >= s.size())
        {
            return;
        }

        if (s[index] == p)
        {
            ans = index;
        }
        solve(s, p, index + 1, ans);
    }

    int LastIndex(string s, char p)
    {
        int index = 0;
        int ans = -1;

        solve(s, p, index, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        char p;
        cin >> p;
        Solution ob;
        cout << ob.LastIndex(s, p) << endl;
    }
    return 0;
}

// } Driver Code Ends