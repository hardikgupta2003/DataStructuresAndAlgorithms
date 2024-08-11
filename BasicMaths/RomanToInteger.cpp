#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<char, int> romanValues = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

public:
    int romanToInt(string s)
    {
        int total = 0;

        for (int i = 0; i < s.size(); i++)
        {

            // If the current value is less than the next value, subtract it from the total
            if (i + 1 < s.size() && romanValues[s[i]] < romanValues[s[i + 1]])
            {
                total -= romanValues[s[i]];
            }
            else
            {
                total += romanValues[s[i]];
            }
        }
        return total;
    }
};