#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        int ans = 0;
        priority_queue<int> pq;
        for (auto i : amount)
        {
            pq.push(i);
        }

        while (pq.top() != 0)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            a--;
            b--;
            pq.push(a);
            pq.push(b);
            ans++;
        }
        return ans;
    }
};