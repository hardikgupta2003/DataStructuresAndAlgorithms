// check if word is valid after substituion
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() == 0)
            return true;
        int fnd = s.find("abc");
        if (fnd != string::npos)
        {
            // found
            string tleft = s.substr(0, fnd);
            string tright = s.substr(fnd + 3, s.size());
            return isValid(tleft + tright);
        }
        return false;
    }
};