#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {

        string ans = "";

        auto myComp =
            [](int &a, int &b)
        {
            string s1 = to_string(a);
            string s2 = to_string(b);

            if (s1 + s2 > s2 + s1)
            {
                return true;
            }
            return false;
        };

        sort(nums.begin(), nums.end(), myComp);

        if (nums[0] == 0)
        {
            return "0";
        }

        for (auto i : nums)
        {
            ans += to_string(i);
        }
        return ans;
    }
};