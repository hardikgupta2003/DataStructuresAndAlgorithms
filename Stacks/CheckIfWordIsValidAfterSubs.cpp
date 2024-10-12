// check if word is valid after substituion
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s[0] != 'a')
            return false;
        // we will try to convert this string into empty string
        // if possible so return true , else false;
        stack<char> st;
        for (auto &ch : s)
        {
            // ch agar 'a' hai toh push kro
            if (ch == 'a')
            {
                st.push(ch);
            }
            else if (ch == 'b')
            {
                // agar ch 'b' hai toh check kro kya top pr 'a' hai ? to make it partial valid
                // push kro 'b' taaki aage jaake 'c' mil paye to make it full valid
                if (!st.empty() && st.top() == 'a')
                {
                    st.push(ch);
                }
                else
                {
                    return false;
                }
            }
            else
            { // ch == 'c'
                // agar ch 'c' hai to check kro top pr 'b' hai? agar hai toh pop kro
                if (!st.empty() && st.top() == 'b')
                {
                    st.pop();
                    // 'b' pop krne ke baad check kro , kya top pr 'a' bhi hai?
                    // agar hai toh mtlb "abc" valid string mil gyi,,,pop kro 'a' ko bhi
                    if (!st.empty() && st.top() == 'a')
                    {
                        st.pop();
                    }
                    // if not return false
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
        // agar stack empty matlb string empty...so string can be transformed, else false
        return st.empty();
    }
};