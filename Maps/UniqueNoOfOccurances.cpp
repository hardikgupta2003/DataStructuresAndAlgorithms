#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        map<int, int> mp;
        map<int, int> mapMp;
        for (auto &it : arr)
        {
            mp[it]++;
        }

        for (auto &it : mp)
        {
            mapMp[it.second]++;
        }
        for (auto &it : mapMp)
        {
            if (it.second > 1)
            {
                return false;
            }
        }
        return true;
    }
};