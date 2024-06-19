// easy leetcode
// valid anagram
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // bool isAnagram(string s, string t)
    // {
    //     if (s.length() != t.length())
    //     {
    //         return false;
    //     }
    //     else
    //     {
    //         sort(s.begin(), s.end());
    //         sort(t.begin(), t.end());
    //         for (int i = 0; i < s.length(); i++)
    //         {
    //             if (s[i] != t[i])
    //             {
    //                 return false;
    //             }
    //         }
    //     }

    //     return true;
    // }
    bool isAnagram(string s, string t)
    {
        int freqTable[256];

        for (auto ch : s)
            freqTable[ch]++;

        for (auto ch : t)
            freqTable[ch]--;

        for (auto ch : freqTable)
            if (ch != 0)
                return false;

        return true;
    }
};