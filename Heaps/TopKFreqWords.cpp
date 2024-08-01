#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    class myComp
    {
    public:
        auto operator()(pair<int, string> &a, pair<int, string> &b)
        {
            if (a.first == b.first)
            {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;
        vector<string> ans;
        for (int i = 0; i < words.size(); i++)
        {
            mp[words[i]]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, myComp> pq;
        for (auto &it : mp)
        {
            pq.push({it.second, it.first});
        }
        while (!pq.empty() && k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};