#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int maxCount = 0; // Initialize maxCount to 0

        stack<int> st; // Stack to store indices
        st.push(-1);   // Base for the first valid substring

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i); // Push the index of '('
            }
            else
            {
                st.pop(); // Pop the previous '(' index
                if (st.empty())
                {
                    st.push(i); // Push the current index as a new base
                }
                else
                {
                    int count = i - st.top();        // Calculate the length of the valid substring
                    maxCount = max(maxCount, count); // Update maxCount if needed
                }
            }
        }

        return maxCount;
    }
};