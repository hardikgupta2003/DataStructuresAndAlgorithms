#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        map<int, int> mp; // element to its next greater element
        stack<int> st;
        for (auto &num : nums2)
        {
            while (!st.empty() && num > st.top())
            {
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // iterate the nums1 and check wheather mapping of its element is
        // present with its next greater or not?

        for (auto &num : nums1)
        {
            if (mp.find(num) != mp.end())
            {
                // found
                ans.push_back(mp[num]);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};