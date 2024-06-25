#include <bits/stdc++.h>
using namespace std;

//recursive way

class Solution
{
public:
    void profit(vector<int> &prices, int &minPrice, int &maxProfit, int i)
    {
        // base case
        if (i >= prices.size())
        {
            return;
        }
        // solve 1 case
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
        else
        {
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        // recursive call
        profit(prices, minPrice, maxProfit, i + 1);
    }
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int minPrice = prices[0];
        int maxProfit = 0;
        profit(prices, minPrice, maxProfit, 1);
        return maxProfit;
    }
};