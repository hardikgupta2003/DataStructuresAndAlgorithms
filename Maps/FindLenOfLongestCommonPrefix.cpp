#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_set<int> st;

        for (auto num : arr1)
        {
            while (num > 0 && st.find(num) == st.end())
            {
                st.insert(num);

                num = num / 10;
            }
        }
        int result = 0;
        for (auto num : arr2)
        {
            while (num > 0 && st.find(num) == st.end())
            {
                num = num / 10;
            }
            if (num > 0)
            {
                result = max(result, static_cast<int>(log10(num) + 1));
            }
        }
        return result;
    }
};