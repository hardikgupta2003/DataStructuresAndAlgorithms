#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        bool flag = false;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && flag == false)
            {
                continue;
            }
            else if (s[i] != ' ')
            {
                flag = true;
                count++;
            }
            else
            {
                break;
            }
        }
        return count;
    }
};
