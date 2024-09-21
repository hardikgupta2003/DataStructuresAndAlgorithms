// easy leetcode and gfg

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    bool sentencePalindrome(string str)
    {
        int start = 0;
        int end = str.length() - 1;

        while (start < end)
        {
            if (!isalnum(str[start]))
            {
                start++;
            }
            else if (!isalnum(str[end]))
            {
                end--;
            }
            else if (tolower(str[start]) != tolower(str[end]))
            {
                return false;
            }
            else
            {
                start++;
                end--;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string str;
        getline(cin, str);
        Solution ob;
        cout << ob.sentencePalindrome(str) << endl;
    }
    return 0;
}

// } Driver Code Ends