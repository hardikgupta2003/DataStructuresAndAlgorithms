// leetcode medium
//  String to Integer atoi
//  code
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// class Solution
// {
// public:
//     int myAtoi(string str)
//     {
//         long long res = 0;
//         int sign = 1;
//         int i = 0;
//         while (i < str.size() && str[i] == ' ')
//             i++;
//         if (i < str.size() && (str[i] == '-' || str[i] ==
//                                                     '+'))
//         {
//             sign = (str[i++] == '-') ? -1 : 1;
//         }
//         while (i < str.size() && str[i] >= '0' && str[i] <= '9')
//         {
//             res = res * 10 + (str[i++] - '0');
//             if (res * sign > INT_MAX)
//                 return INT_MAX;
//             if (res * sign < INT_MIN)
//                 return INT_MIN;
//         }
//         return res * sign;
//     }
// };
class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        int num = 0;
        int sign = 1;

        while (i < s.size() && s[i] == ' ')
        {
            i++;
        }

        while (i < s.size() && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
            break;
        }

        while (i < s.size() && isdigit(s[i]))
        {
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7'))
            {
                return (sign == -1) ? INT_MIN : INT_MAX;
            }

            num = num * 10 + (s[i] - '0');
            i++;
        }

        return (sign == -1) ? -num : num;
    }
};
// Explanation in points

// 1. We start by initializing a variable res to store the result and a variable sign to
// store the sign of the number.
// 2. We then skip all the leading spaces in the string.
// 3. If the string starts with a '+' or '-' sign, we update the sign variable accordingly
// and move to the next character.
// 4. We then start parsing the digits of the number. For each digit, we multiply the
// current result by 10 and add the digit.
// 5. We also check for overflow at each step. If the result exceeds the maximum
// integer value or is less than the minimum integer value, we return the maximum
// or minimum integer value respectively.
// 6. Finally, we return the result multiplied by the sign.
// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), as we are using a constant amount of space.
