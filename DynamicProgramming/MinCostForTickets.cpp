// leetcode medium
// minimum cost for tickets
// https://leetcode.com/problems/minimum-cost-for-tickets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solveByMemoization(vector<int> &days, vector<int> &costs, int index, vector<int> &dp)
    {
        // base case
        int n = days.size();
        if (index >= n)
            return 0;

        if (dp[index] != -1)
            return dp[index];
        // solve 1 case
        // 1 day pass taken
        int cost1 = costs[0] + solveByMemoization(days, costs, index + 1, dp);

        // 7 day pass taken
        int passEndDay = days[index] + 7 - 1;
        int j = index;
        while (j < n && days[j] <= passEndDay)
        {
            j++;
        }
        int cost7 = costs[1] + solveByMemoization(days, costs, j, dp);

        // 30 day pass taken
        passEndDay = days[index] + 30 - 1;
        j = index;
        while (j < n && days[j] <= passEndDay)
        {
            j++;
        }
        int cost30 = costs[2] + solveByMemoization(days, costs, j, dp);

        return dp[index] = min(cost1, min(cost7, cost30));
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(days.size() + 1, -1);
        return solveByMemoization(days, costs, 0, dp);
    }
};

// by tabulation
class Solution
{
public:
    int solveByTab(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> dp(n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            // 1 day pass taken
            int cost1 = costs[0] + dp[index + 1];

            // 7 day pass taken
            int passEndDay = days[index] + 7 - 1;
            int j = index;
            while (j < n && days[j] <= passEndDay)
            {
                j++;
            }
            int cost7 = costs[1] + dp[j];

            // 30 day pass taken
            passEndDay = days[index] + 30 - 1;
            j = index;
            while (j < n && days[j] <= passEndDay)
            {
                j++;
            }
            int cost30 = costs[2] + dp[j];

            dp[index] = min(cost1, min(cost7, cost30));
        }
        return dp[0];
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        return solveByTab(days, costs);
    }
}; 