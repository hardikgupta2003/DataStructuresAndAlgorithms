#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    class myComp
    {
    public:
        auto operator()(pair<int, char> &a, pair<int, char> &b)
        {
            if (a.first == b.first)
            {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
    string frequencySort(string s)
    {
        map<char, int> mp;
        string ans = "";
        for (auto it : s)
        {
            mp[it]++;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>, myComp> pq;
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            while (top.first > 0)
            {
                ans.push_back(top.second);
                top.first--;
            }
        }
        return ans;
    }
};