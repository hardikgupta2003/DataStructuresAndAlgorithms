// leetcode hard
// sliding window maximum
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> dq;

        // first window process karlo
        for (int i = 0; i < k; i++)
        {
            int element = nums[i];
            // jitne bhi queue ke andr chote elements hai unko remove krdo back se
            while (!dq.empty() && element > nums[dq.back()])
            {
                dq.pop_back();
            }
            // now insert krdo (any how karna hi hai)
            dq.push_back(i);
        }
        // remaining window process krlo
        // removal
        // addition
        for (int i = k; i < nums.size(); i++)
        {
            // store ans
            ans.push_back(nums[dq.front()]);

            // removal
            // out of range wale remove krenge
            if (!dq.empty() && i - dq.front() >= k)
            {
                dq.pop_front();
            }
            // chote element remove krna hai
            int element = nums[i];
            // jitne bhi queue ke andr chote elements hai unko remove krdo back se
            while (!dq.empty() && element > nums[dq.back()])
            {
                dq.pop_back();
            }
            // now insert krdo (any how karna hi hai) // addition of extra
            dq.push_back(i);
        }
        // last window ka answer store krlo
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};
