#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n < 0)
            return false;
        int count = 0;
        while (n != 0)
        {
            int lastBit = n & 1;
            if (lastBit == 1)
            {
                count++;
            }
            n = n >> 1;
        }
        return count == 1;
    }
};

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        return (n & (n - 1)) == 0;
    }
};