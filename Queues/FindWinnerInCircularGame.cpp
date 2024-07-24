#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int> q;
        // all players should go inside the queue
        for (int i = 1; i <= n; i++)
        {
            q.push(i);
        }
        while (q.size() != 1)
        {
            // simulate the game
            for (int i = 1; i < k; i++)
            {
                int front = q.front();
                q.pop();

                // it is not eliminated yet
                q.push(front);
            }
            // kth player must be eliminated
            q.pop();
        }
        // winner
        return q.front();
    }
};