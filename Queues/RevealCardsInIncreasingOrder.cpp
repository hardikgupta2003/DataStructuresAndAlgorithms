#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end());
        queue<int> q;
        vector<int> ans(deck.size());

        // put incdices of ans into q
        for (int i = 0; i < ans.size(); i++)
        {
            q.push(i);
        }
        // reverse simulation + filling using sorted deck
        for (int i = 0; i < deck.size(); i++)
        {
            // 1. reveal
            ans[q.front()] = deck[i];
            q.pop();

            // 2. push front to bottom
            if (!q.empty())
            {
                int front = q.front();
                q.pop();
                q.push(front);
            }
        }
        return ans;
    }
};