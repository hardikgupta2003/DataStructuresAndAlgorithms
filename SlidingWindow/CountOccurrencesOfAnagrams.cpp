// leetcode gfg medium

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int search(string pat, string txt)
    {
        int ans = 0;
        int n = txt.size();
        int m = pat.size();

        if (m > n)
            return 0; // Edge case: pattern longer than text

        unordered_map<char, int> patMap, windowMap;

        // Fill frequency map for the pattern
        for (auto &ch : pat)
        {
            patMap[ch]++;
        }

        // Check all substrings of length 'm'
        for (int i = 0; i < n; i++)
        {
            // Add current character to the window map
            windowMap[txt[i]]++;

            // Remove the character that is left out of the window
            if (i >= m)
            {
                if (windowMap[txt[i - m]] == 1)
                {
                    windowMap.erase(txt[i - m]);
                }
                else
                {
                    windowMap[txt[i - m]]--;
                }
            }
            // Compare current window with the pattern map
            if (windowMap == patMap)
            {
                ans++;
            }
        }

        return ans;
    }
};




// leetcode

class Solution
{
public:
    vector<int> findAnagrams(string txt, string pat)
    {
        vector<int> ans;
        int n = txt.size();
        int m = pat.size();

        unordered_map<char, int> patMap, windowMap;

        // Fill frequency map for the pattern
        for (auto &ch : pat)
        {
            patMap[ch]++;
        }

        // Check all substrings of length 'm'
        for (int i = 0; i < n; i++)
        {
            // Add current character to the window map
            windowMap[txt[i]]++;

            // Remove the character that is left out of the window
            if (i >= m)
            {
                if (windowMap[txt[i - m]] == 1)
                {
                    windowMap.erase(txt[i - m]);
                }
                else
                {
                    windowMap[txt[i - m]]--;
                }
            }
            // Compare current window with the pattern map
            if (windowMap == patMap)
            {
                ans.push_back(i - m + 1);
            }
        }

        return ans;
    }
};