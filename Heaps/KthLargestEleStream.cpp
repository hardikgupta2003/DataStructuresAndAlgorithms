#include "bits/stdc++.h"
using namespace std;

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap to store K largest elements
    int K;

    KthLargest(int k, vector<int> &nums)
    {
        K = k;
        for (int num : nums)
        {
            add(num);
        }
    }

    int add(int val)
    {
        if (pq.size() < K)
        {
            pq.push(val);
        }
        else if (val > pq.top())
        {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};