#include <bits/stdc++.h>
using namespace std;

// greedy algo
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

// recursion algo
class Solution
{
public:
    int solve(vector<int> &prices, int index, int buy)
    {
        if (index == prices.size())
        {
            return 0;
        }
        int maxProfit = 0;
        // buy==1 khareed sakte hai
        if (buy)
        {
            // kharid lo
            int buyKaro = -prices[index] + solve(prices, index + 1, 0);
            // skip krdo
            int skipKaro = 0 + solve(prices, index + 1, 1);
            maxProfit = max(buyKaro, skipKaro);
        }
        // buy == 0 kharid nahi sakte, already khareeda hua hai
        else
        {
            // bech do
            int sellKaro = +prices[index] + solve(prices, index + 1, 1);
            // skip krdo
            int skipKaro = 0 + solve(prices, index + 1, 0);
            maxProfit = max(sellKaro, skipKaro);
        }
        return maxProfit;
    }
    int maxProfit(vector<int> &prices)
    {
        return solve(prices, 0, 1);
    }
};

//memoization - top down approach
class Solution
{
public:
    int solve(vector<int> &prices, int index, int buy, vector<vector<int>> &dp)
    {
        if (index == prices.size())
        {
            return 0;
        }

        if (dp[index][buy] != -1)
            return dp[index][buy];

        int maxProfit = 0;
        // buy==1 khareed sakte hai
        if (buy)
        {
            // kharid lo
            int buyKaro = -prices[index] + solve(prices, index + 1, 0, dp);
            // skip krdo
            int skipKaro = 0 + solve(prices, index + 1, 1, dp);
            maxProfit = max(buyKaro, skipKaro);
        }
        // buy == 0 kharid nahi sakte, already khareeda hua hai
        else
        {
            // bech do
            int sellKaro = +prices[index] + solve(prices, index + 1, 1, dp);
            // skip krdo
            int skipKaro = 0 + solve(prices, index + 1, 0, dp);
            maxProfit = max(sellKaro, skipKaro);
        }
        return dp[index][buy] = maxProfit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, 1, dp);
    }
};

// tabulation
class Solution
{
public:
    int solveByTabulation(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int maxProfit = 0;
                // buy==1 khareed sakte hai
                if (buy)
                {
                    // kharid lo
                    int buyKaro = -prices[index] + dp[index + 1][0];
                    // skip krdo
                    int skipKaro = 0 + dp[index + 1][1];
                    maxProfit = max(buyKaro, skipKaro);
                }
                // buy == 0 kharid nahi sakte, already khareeda hua hai
                else
                {
                    // bech do
                    int sellKaro = +prices[index] + dp[index + 1][1];
                    // skip krdo
                    int skipKaro = 0 + dp[index + 1][0];
                    maxProfit = max(sellKaro, skipKaro);
                }
                dp[index][buy] = maxProfit;
            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int> &prices)
    {
        return solveByTabulation(prices);
    }
};

// space optimization
class Solution
{
public:
    int solveByTabulationSO(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> next(2, 0);
        vector<int> curr(2, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int maxProfit = 0;
                // buy==1 khareed sakte hai
                if (buy)
                {
                    // kharid lo
                    int buyKaro = -prices[index] + next[0];
                    // skip krdo
                    int skipKaro = 0 + next[1];
                    maxProfit = max(buyKaro, skipKaro);
                }
                // buy == 0 kharid nahi sakte, already khareeda hua hai
                else
                {
                    // bech do
                    int sellKaro = +prices[index] + next[1];
                    // skip krdo
                    int skipKaro = 0 + next[0];
                    maxProfit = max(sellKaro, skipKaro);
                }
                curr[buy] = maxProfit;
            }
            next = curr;
        }
        return curr[1];
    }

    int maxProfit(vector<int> &prices)
    {
        return solveByTabulationSO(prices);
    }
};