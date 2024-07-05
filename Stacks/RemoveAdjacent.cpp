#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        string ans = "";
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (!st.empty() && ch == st.top())
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
        while (!st.empty())
        {
            char top = st.top();
            st.pop();
            ans.push_back(top);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};