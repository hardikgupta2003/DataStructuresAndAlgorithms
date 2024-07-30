#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (!st.empty() && abs(ch - st.top()) == 32)
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
        cout << 'a' - 'A';
        string ans = "";
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};