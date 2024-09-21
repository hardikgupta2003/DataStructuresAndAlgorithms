#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getLucky(string s, int k)
    {
        int ans = -1;
        string transformed = "";

        // Map characters to their corresponding positions
        map<char, int> mp;
        int pos = 1;
        for (char i = 'a'; i <= 'z'; i++)
        {
            mp[i] = pos++;
        }

        // Transform the string `s` into a numeric string
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            transformed += to_string(mp[ch]);
        }

        cout << "Transformed String: " << transformed << endl;

        // Apply the transformation `k` times
        while (k--)
        {
            int sum = 0;
            for (char c : transformed)
            {
                sum += (c - '0'); // Convert char digit to int and sum it up
            }
            ans = sum;
            transformed = to_string(sum); // Update `transformed` with the new sum as string
        }

        return ans;
    }
};
