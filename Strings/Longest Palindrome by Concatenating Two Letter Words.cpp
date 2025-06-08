#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        int ans = 0;
        map<string, int> map;
        bool hasMiddle = false;

        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            string revWord = word;
            reverse(revWord.begin(), revWord.end());

            if (word == revWord)
            {
                if (map[word] == 1)
                { // make a pair
                    ans += 4;
                    map[word] = 0;
                }
                else
                {
                    map[word]++;
                }
            }
            else
            {
                if (map[revWord] > 0)
                {
                    ans += 4;
                    map[revWord]--;
                }
                else
                {
                    map[word]++;
                }
            }
        }

        // add one palindromic word in the middle
        for (auto &p : map)
        {
            if (p.first[0] == p.first[1] && p.second > 0)
            {
                ans += 2;
                break;
            }
        }

        return ans;
    }
};
