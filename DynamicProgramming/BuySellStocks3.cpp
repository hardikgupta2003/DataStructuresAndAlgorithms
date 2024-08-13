//  leetcode hard
#include <bits/stdc++.h>
using namespace std;

// recursion
class Solution
{
public:
    int solve(vector<int> &prices, int index, int buy, int limit)
    {
        if (index == prices.size())
        {
            return 0;
        }
        if (limit == 0)
            return 0;
        int maxProfit = 0;
        // buy==1 khareed sakte hai
        if (buy)
        {
            // kharid lo
            int buyKaro = -prices[index] + solve(prices, index + 1, 0, limit);
            // skip krdo
            int skipKaro = 0 + solve(prices, index + 1, 1, limit);
            maxProfit = max(buyKaro, skipKaro);
        }
        // buy == 0 kharid nahi sakte, already khareeda hua hai
        else
        {
            // bech do
            int sellKaro = +prices[index] + solve(prices, index + 1, 1, limit - 1);
            // skip krdo
            int skipKaro = 0 + solve(prices, index + 1, 0, limit);
            maxProfit = max(sellKaro, skipKaro);
        }
        return maxProfit;
    }
    int maxProfit(vector<int> &prices)
    {
        return solve(prices, 0, 1, 2);
    }
};


// memoization 3D dp 
class Solution
{
public:
    int solve(vector<int> &prices, int index, int buy, int limit, vector<vector<vector<int>>> &dp)
    {
        if (index == prices.size())
        {
            return 0;
        }
        if (limit == 0)
            return 0;

        if (dp[index][buy][limit] != -1)
            return dp[index][buy][limit];
        int maxProfit = 0;
        // buy==1 khareed sakte hai
        if (buy)
        {
            // kharid lo
            int buyKaro = -prices[index] + solve(prices, index + 1, 0, limit, dp);
            // skip krdo
            int skipKaro = 0 + solve(prices, index + 1, 1, limit, dp);
            maxProfit = max(buyKaro, skipKaro);
        }
        // buy == 0 kharid nahi sakte, already khareeda hua hai
        else
        {
            // bech do
            int sellKaro = +prices[index] + solve(prices, index + 1, 1, limit - 1, dp);
            // skip krdo
            int skipKaro = 0 + solve(prices, index + 1, 0, limit, dp);
            maxProfit = max(sellKaro, skipKaro);
        }
        return dp[index][buy][limit] = maxProfit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, 0, 1, 2, dp);
    }
};

// tabulation 3d dp
class Solution
{
public:
    int solveByTabulation(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= 2; limit++)
                {
                    int maxProfit = 0;
                    // buy==1 khareed sakte hai
                    if (buy)
                    {
                        // kharid lo
                        int buyKaro = -prices[index] + dp[index + 1][0][limit];
                        // skip krdo
                        int skipKaro = 0 + dp[index + 1][1][limit];
                        maxProfit = max(buyKaro, skipKaro);
                    }
                    // buy == 0 kharid nahi sakte, already khareeda hua hai
                    else
                    {
                        // bech do
                        int sellKaro = +prices[index] + dp[index + 1][1][limit - 1];
                        // skip krdo
                        int skipKaro = 0 + dp[index + 1][0][limit];
                        maxProfit = max(sellKaro, skipKaro);
                    }
                    dp[index][buy][limit] = maxProfit;
                }
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int> &prices)
    {
        return solveByTabulation(prices);
    }
};