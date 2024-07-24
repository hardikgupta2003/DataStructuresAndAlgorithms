#include <bits/stdc++.h>
using namespace std;

class RecentCounter
{
    queue<int> q;

public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        // 1. push krdo t
        q.push(t);
        // 2. pop invalid req , older than t-3000
        // agar front pr t-3000 se choti req hai toh remove krdo
        while (!q.empty() && q.front() < (t - 3000))
        {
            q.pop();
        }
        // 3. after poping , sirf range wali req hi hogi
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */