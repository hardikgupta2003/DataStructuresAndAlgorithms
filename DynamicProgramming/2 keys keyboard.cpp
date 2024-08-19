#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, int currLen, int pasteLen)
    {
        // base case : reached n A's , dont need more operations
        if (currLen == n)
            return 0;
        // base case : exceeded n A's ,not a valid sequences , return max value;
        if (currLen > n)
            return 1000;

        // copy all + paste
        int op1 = 2 + solve(n, currLen * 2, currLen);
        // paste only
        int op2 = 1 + solve(n, currLen + pasteLen, pasteLen);

        return min(op1, op2);
    }
    int minSteps(int n)
    {
        if (n == 1)
            return 0;

        // first step is always copy all operation , so add 1
        return 1 + solve(n, 1, 1);
    }
};