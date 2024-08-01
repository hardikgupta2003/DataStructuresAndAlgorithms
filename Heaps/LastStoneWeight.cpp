#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {

        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i++)
        {
            pq.push(stones[i]);
        }

        while (pq.size() > 1)
        {
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();

            if (stone1 > stone2)
            {
                // ignore stone 2 coz it is destroyed
                //  stone 1 has new weight now
                pq.push(stone1 - stone2);
            }
            else if (stone1 < stone2)
            {
                // ignore stone 1 coz it is destroyed
                //  stone 2 has new weight now
                pq.push(stone2 - stone1);
            }
            if (pq.empty())
                return 0;
        }
        return pq.top();
    }
};