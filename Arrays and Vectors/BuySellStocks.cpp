// leetcode easy
// best time to buy and sell stocks
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// code
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            else
            {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }
        return maxProfit;
    }
};

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0];
        int maxProfit = 0;
        int n = prices.size();

        for (int i = 1; i < n; i++)
        {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};