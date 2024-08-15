#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;

        for (int bill : bills)
        {
            if (bill == 5)
            {
                five += 1;
            }
            else if (bill == 10)
            {
                if (five == 0)
                {
                    return false; // No $5 bill to give as change
                }
                five -= 1;
                ten += 1;
            }
            else
            { // bill == 20
                // Priority: use one $10 and one $5 bill if possible
                if (ten > 0 && five > 0)
                {
                    ten -= 1;
                    five -= 1;
                }
                // If not possible, use three $5 bills
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false; // No valid change possible
                }
            }
        }
        return true; // Successfully gave change to all customers
    }
};
