// using heap
#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto num : nums)
        {
            pq.push(num);
        }
        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};