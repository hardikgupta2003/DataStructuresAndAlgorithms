#include "bits/stdc++.h"
using namespace std;

// max heap
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, vector<int>>> pq;
        vector<vector<int>> ans;
        for (auto &point : points)
        {
            int dist = pow(point[0], 2) + pow(point[1], 2);
            pq.push({dist, point});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        for (int i = 0; i < k; ++i)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

// min heap
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        vector<vector<int>> ans;
        for (auto &point : points)
        {
            int dist = pow(point[0], 2) + pow(point[1], 2);
            pq.push({dist, point});
        }
        for (int i = 0; i < k; ++i)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};