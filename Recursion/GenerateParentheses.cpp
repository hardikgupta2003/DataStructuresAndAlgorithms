#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<string> ans;
    bool isValid(string &s)
    {
        if (s[0] == ')')
            return false;
        int count = 0;
        for (auto &i : s)
        {
            if (i == '(')
            {
                count++;
            }
            else
            {
                count--;
                if (count < 0)
                    return false;
            }
        }
        return count == 0;
    }
    bool isValid(string &s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if (ch == '(')
            {
                st.push(ch);
            }
            else
            {
                if (!st.empty())
                {
                    if (st.top() == '(' && ch == ')')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (st.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    void solve(string &curr, int n)
    {
        if (curr.size() == 2 * n)
        {
            if (isValid(curr))
            {
                ans.push_back(curr);
            }
            return;
        }

        curr.push_back('(');
        solve(curr, n);

        curr.pop_back();

        curr.push_back(')');
        solve(curr, n);

        curr.pop_back();
    }
    vector<string> generateParenthesis(int n)
    {
        if (n == 1)
            return {"()"};
        string curr = "";
        solve(curr, n);
        return ans;
    }
};

class Solution
{
    vector<string> ans;
    void solve(string &curr, int n, int open, int close)
    {
        if (curr.size() == 2 * n)
        {
            ans.push_back(curr);
            return;
        }

        if (open < n)
        {
            curr.push_back('(');
            solve(curr, n, open + 1, close);

            curr.pop_back();
        }

        if (close < open)
        {
            curr.push_back(')');
            solve(curr, n, open, close + 1);

            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        if (n == 1)
            return {"()"};
        string curr = "";
        int open = 0;
        int close = 0;
        solve(curr, n, open, close);
        return ans;
    }
};