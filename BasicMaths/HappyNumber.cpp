// math and hashmap

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        // Use a set to track numbers we've seen to detect cycles
        unordered_set<int> seen;

        while (n != 1 && seen.find(n) == seen.end())
        {
            seen.insert(n);
            int sum = 0;

            // Calculate the sum of the square of the digits
            while (n > 0)
            {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }

            n = sum;
        }

        // If we end with 1, it's a happy number; otherwise, it's not.
        return n == 1;
    }
};