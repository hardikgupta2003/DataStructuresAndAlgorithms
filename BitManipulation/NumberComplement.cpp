#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findComplement(int num)
    {
        if (num == 1)
            return 0;
        int m = num;
        int ans = 0;
        int index = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((m & 1) == 1)
            {
                index = i;
            }
            m = m >> 1;
        }
        int mask = (-1 << (index + 1));

        ans = num ^ mask;
        return ~ans;
    }
};