#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        stack<char> st;
        int maxCount = 0;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == '(')
            {
                st.push(ch);
                count = st.size();
                maxCount = max(maxCount, count);
            }
            else if (ch == ')')
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                continue;
            }
        }
        return maxCount;
    }
};