// leetcode easy
// Ransome note
//code

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < ransomNote.size(); i++)
        {
            mp[ransomNote[i]]++;
        }
        for (int i = 0; i < magazine.size(); i++)
        {
            mp[magazine[i]]--;
        }

        for (int i = 0; i < mp.size(); i++)
        {
            if (mp[i] > 0)
            {
                return false;
            }
        }
        return true;
    }
};