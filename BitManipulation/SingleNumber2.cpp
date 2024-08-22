#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;

        for (int k = 0; k <= 31; k++)
        {
            int temp = (1 << k);
            int countOnes = 0;
            for (int &num : nums)
            {
                if ((num & temp) != 0)
                {
                    countOnes++;
                }
            }
            if (countOnes % 3 == 1)
            {
                result = result | temp;
            }
        }
        return result;
    }
};