#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();

        // Start from the end of the array
        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                // If current digit is less than 9, increment it by 1 and return the result
                digits[i]++;
                return digits;
            }
            // If current digit is 9, set it to 0 and continue to the next digit
            digits[i] = 0;
        }

        // If all digits were 9, we need an extra digit at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};