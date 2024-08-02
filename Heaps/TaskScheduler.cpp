#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        map<char, int> mp;

        for (auto &task : tasks)
        {
            mp[task]++;
        }

        int time = 0;
        priority_queue<int> pq;
        for (auto &it : mp)
        {
            pq.push(it.second);
        }

        while (!pq.empty())
        {
            vector<int> temp;
            for (int i = 1; i <= n + 1; i++)
            {
                if (!pq.empty())
                {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            // put the remaining tasks back into the max heap with updated frequencies
            for (int &f : temp)
            {
                if (f > 0)
                {
                    pq.push(f);
                }
            }

            if (pq.empty())
            {
                time += temp.size();
            }
            else
            {
                time += n + 1;
            }
        }
        return time;
    }
};