#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        map<int, int> mp; // (value,count);
        for (auto &it : arr)
        {
            mp[it]++;
        }
        priority_queue<int> pq;
        for (auto it : mp)
        {
            pq.push(it.second);
        }
        int ans = 0;
        int need = arr.size() / 2;
        while (need > 0)
        {
            ans++;
            need -= pq.top();
            pq.pop();
        }
        return ans;
    }
};