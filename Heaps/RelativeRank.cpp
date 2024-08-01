#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<string> ans(score.size());
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < score.size(); i++)
        {
            pq.push({score[i], i});
        }
        if (!pq.empty())
        {
            auto top = pq.top();
            ans[top.second] = "Gold Medal";
            pq.pop();
        }
        if (!pq.empty())
        {
            auto top = pq.top();
            ans[top.second] = "Silver Medal";
            pq.pop();
        }
        if (!pq.empty())
        {
            auto top = pq.top();
            ans[top.second] = "Bronze Medal";
            pq.pop();
        }
        int rank = 4;
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            ans[top.second] = to_string(rank);
            rank++;
        }
        return ans;
    }
};
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int lenScore = score.size();
        vector<string> answer(lenScore);
        priority_queue<pair<int, int>>
            maxHeap; // max heap to store scores with indices

        // Fill the heap with scores and their corresponding indices
        for (int i = 0; i < lenScore; ++i)
        {
            maxHeap.push({score[i], i});
        }

        vector<string> rank = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        // Assign ranks based on the max heap
        int number = 1;
        while (!maxHeap.empty())
        {
            auto top = maxHeap.top();
            maxHeap.pop();
            int index = top.second;
            if (number < 4)
            {
                answer[index] = rank[number - 1];
            }
            else
            {
                answer[index] = to_string(number);
            }
            number++;
        }

        return answer;
    }
};