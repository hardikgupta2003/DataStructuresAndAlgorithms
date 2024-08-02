#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        while (!pq.empty())
        {
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();

            ans.push_back(top2);
            ans.push_back(top1);
        }
        return ans;
    }
};