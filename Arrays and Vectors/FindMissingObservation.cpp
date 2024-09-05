#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {

        int numSum = 0;
        for (int &i : rolls)
        {
            numSum += i;
        }

        int m = rolls.size();
        int totalLen = n + m;

        int mNumSum = mean * totalLen - numSum;

        if (n * 6 < mNumSum || mNumSum < n)
            return {};

        int rem = mNumSum % n;
        int q = mNumSum / n;

        vector<int> ans(n, q);
        for (int i = 1; i <= rem; i++)
        {
            ans[i]++;
        }
        return ans;
    }
};