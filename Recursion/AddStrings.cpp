//leetcode easy
// add strings
// code
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(string &num1, string &num2, int p1, int p2, int carry, string &ans)
    {
        if (p1 < 0 && p2 < 0)
        {
            if (carry != 0)
            {
                ans.push_back(carry + '0');
            }
            return;
        }
        int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
        int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';

        int csum = n1 + n2 + carry;
        int digit = csum % 10;
        carry = csum / 10;

        ans.push_back(digit + '0');
        solve(num1, num2, p1 - 1, p2 - 1, carry, ans);
    }
    string addStrings(string num1, string num2)
    {
        string ans = "";
        solve(num1, num2, num1.size() - 1, num2.size() - 1, 0, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//  easy explainating comments and recusive approach
// 1. we create a function solve which takes two strings num1 and num2 and two
// pointers p1 and p2 which points to the last character of num1 and num2 respectively
// and a carry variable which is initially 0
// 2. we check if both p1 and p2 are less than 0 then we
// return an empty string if carry is 0 else we return a string with carry
// 3. we calculate the sum of the current digits of num1 and num2 and the
// carry and store it in csum
// 4. we calculate the digit and carry for the next recursive call
// 5. we add the digit to the answer string and recursively call the solve
// function with p1-1 and p2-1 and the new carry
// 6. finally we reverse the answer string and return it

