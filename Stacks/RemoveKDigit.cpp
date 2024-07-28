#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string ans;
        stack<char> st;
        for (int i = 0; i < num.size(); i++)
        {
            if (k > 0)
            {
                while (!st.empty() && num[i] < st.top() && k > 0)
                {
                    char front = st.top();
                    st.pop();
                    k--;
                    if (k == 0)
                    {
                        break;
                    }
                }
            }
            st.push(num[i]);
        }
        while (!st.empty() && k > 0)
        {
            st.pop();
            k--;
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        // remove zeros from back
        while (ans.size() > 0 && ans.back() == '0')
        {
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());
        return ans == "" ? "0" : ans;
    }
};