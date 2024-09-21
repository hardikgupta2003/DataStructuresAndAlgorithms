#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        stringstream str1(s1);
        stringstream str2(s2);
        vector<string> ans;
        map<string, int> mp;

        string token = "";
        while (str1 >> token)
        {
            mp[token]++;
        }
        token = "";
        while (str2 >> token)
        {
            mp[token]++;
        }
        for (auto &i : mp)
        {
            if (i.second == 1)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};