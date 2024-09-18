#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length(); // Length of string 's'

        // If 't' is longer than 's', it's impossible to have a valid substring
        if (t.length() > n)
        {
            return "";
        }

        unordered_map<char, int> mp;
        // Populate frequency map for characters in 't'
        for (auto &ch : t)
        {
            mp[ch]++;
        }

        int requiredCount = t.length(); // Total characters we need to match
        int i = 0, j = 0;               // 'i' and 'j' are the two pointers for the sliding window

        int minWindowSize = INT_MAX; // To store the minimum window size
        int start_i = 0;             // To store the starting index of the smallest window

        // Start expanding the window by moving 'j'
        while (j < n)
        {
            char ch = s[j]; // Get the current character in the window

            // If this character is in 't', reduce the required count
            if (mp[ch] > 0)
            {
                requiredCount--;
            }
            // Decrease the frequency of the current character in the map
            mp[ch]--;

            // If all characters are matched (requiredCount == 0), start shrinking the window
            while (requiredCount == 0)
            {
                int currWindowSize = j - i + 1; // Current window size

                // Update the minimum window size if we find a smaller valid window
                if (minWindowSize > currWindowSize)
                {
                    minWindowSize = currWindowSize;
                    start_i = i; // Update the start index of the minimum window
                }

                // Move the left pointer 'i' to shrink the window
                mp[s[i]]++; // Increment the frequency of the character at 'i'

                // If this character becomes part of 't' again, we need to match it, so increase the requiredCount
                if (mp[s[i]] > 0)
                {
                    requiredCount++;
                }
                i++; // Move the left pointer to shrink the window
            }
            j++; // Expand the window by moving the right pointer 'j'
        }

        // If no valid window was found, return an empty string
        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};
