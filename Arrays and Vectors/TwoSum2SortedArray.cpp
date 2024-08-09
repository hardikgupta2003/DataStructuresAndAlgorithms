#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> ans;

public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int start = 0;
        int end = numbers.size() - 1;
        while (start < end)
        {
            int sum = numbers[start] + numbers[end];
            if (sum == target)
            {
                ans.push_back(start + 1);
                ans.push_back(end + 1);
                break;
            }
            else if (target < sum)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return ans;
    }
};