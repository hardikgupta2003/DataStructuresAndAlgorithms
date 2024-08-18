#include <bits/stdc++.h>
using namespace std;

// tle 
class Solution
{
public:
    bool isUgly(int n)
    {
        if (n == 1)
            return true;
        if (n <= 0)
            return false;
        while (n > 1)
        {
            if (n % 2 == 0)
            {
                n = n / 2;
            }
            else if (n % 3 == 0)
            {
                n = n / 3;
            }
            else if (n % 5 == 0)
            {
                n = n / 5;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    int nthUglyNumber(int n)
    {
        int count = 0;
        int num = 1;
        int ans = 0;
        while (count <= n)
        {
            if (isUgly(num))
            {
                ans = num;
                count++;
            }
            num++;
        }
        return ans;
    }
};

// optimal with dp
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> arr(n + 1);
        // t[i] = ith ugly number
        // t[n] = nth ugly number
        //  return t[n]

        int i2, i3, i5;

        // all this pointing to the first ugly no.
        i2 = i3 = i5 = 1;

        // first ugly no. is 1
        arr[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            int i2UglyNum = arr[i2] * 2;
            int i3UglyNum = arr[i3] * 3;
            int i5UglyNum = arr[i5] * 5;

            int minUglyNum = min({i2UglyNum, i3UglyNum, i5UglyNum});

            arr[i] = minUglyNum;
            // jska minimum hua uske pointer ko aage badha do
            if (minUglyNum == i2UglyNum)
            {
                i2++;
            }
            if (minUglyNum == i3UglyNum)
            {
                i3++;
            }
            if (minUglyNum == i5UglyNum)
            {
                i5++;
            }
        }
        return arr[n]; // nth ugly number
    }
};