// medium leetcode 
// remove all adjacent in string 2
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
#include <bits/stdc++.h>
using namespace std;
string removeDuplicates(string s, int k)
{
    stack<pair<char, int>> st;
    for (char c : s)
    {
        if (st.size() && st.top().first == c)
        {
            st.top().second++;
            if (st.top().second == k)
                st.pop();
        }
        else
        {
            st.push({c, 1});
        }
    }
    string res = "";
    while (st.size())
    {
        res += string(st.top().second, st.top().first);
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
                        }

