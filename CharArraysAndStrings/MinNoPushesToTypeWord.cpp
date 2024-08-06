#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        int ans = 0;

        unordered_map<int, int> mp;
        int assign_key = 2;

        for (auto &ch : word)
        {
            if (assign_key > 9)
            {
                assign_key = 2;
            }

            mp[assign_key]++;
            ans += mp[assign_key];

            assign_key++;
        }
        return ans;
    }
};

class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> mp(26, 0);
        for (auto &ch : word)
        {
            mp[ch - 'a']++;
        }
        int ans = 0;
        sort(begin(mp), end(mp), greater<int>());
        for (int i = 0; i < 26; i++)
        {
            int freq = mp[i];
            int press = (i / 8 + 1);
            ans += freq * press;
        }
        return ans;
    }
};