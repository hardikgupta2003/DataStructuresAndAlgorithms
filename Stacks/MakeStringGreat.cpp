#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {
        string ans = "";
        stack<char> st;
        // traverse the string
        for (auto ch : s)
        {
            // if stack is not empty and difference between char and stack top is 32 ->
            // they are same alphabets but in different case
            if (!st.empty() && abs(ch - st.top()) == 32)
            {
                st.pop();
            }
            else
            {
                // not same with dfferent case ..so push
                st.push(ch);
            }
        }
        // store value of stack to string
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        // reverse the string
        reverse(ans.begin(), ans.end());
        return ans;
    }
};