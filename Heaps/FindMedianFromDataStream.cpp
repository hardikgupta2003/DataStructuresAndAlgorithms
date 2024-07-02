// leetcode Hard
// Find Median From Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/description/
// code
#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxheap.size() == 0 || num < maxheap.top())
        {
            maxheap.push(num);
        }
        else
        {
            minheap.push(num);
        }

        // both heaps must have same no of elements.
        // if not , maxheap must have 1 more element that minheap

        if (maxheap.size() < minheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        else if (maxheap.size() > minheap.size() + 1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }

    double findMedian()
    {
        if (maxheap.size() == minheap.size())
        {
            return (maxheap.top() + minheap.top()) / 2.0;
        }

        // non matching case
        // pehle se hi maintained hai ki , max heap me hoga answer
        // if maxheap.size() is not equal to minheap.size()

        return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */