#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string roman = "";
        vector<int> value{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbol{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        for (int i = 0; i < 13; i++)
        {

            int times = num / value[i];
            while (times--)
            {
                roman += symbol[i];
            }
            num = num % value[i];
        }
        return roman;
    }
};
class Solution
{
public:
    string intToRoman(int num)
    {
        string roman = "";
        vector<pair<int, string>> IntegerValues = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        for (auto &value : IntegerValues)
        {

            int times = num / value.first;
            while (times--)
            {
                roman += value.second;
            }
            num = num % value.first;
        }
        return roman;
    }
};

// using substraction
class Solution
{
public:
    string intToRoman(int num)
    {
        string roman = "";
        vector<pair<int, string>> IntegerValues = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        for (auto &value : IntegerValues)
        {

            while (num >= value.first)
            {
                roman += value.second;
                num -= value.first;
            }
        }
        return roman;
    }
};