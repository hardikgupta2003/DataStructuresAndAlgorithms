#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> words;
        stringstream ss(s);
        string token;
        int count = 0;

        // Split the string `s` into words based on spaces
        while (getline(ss, token, ' '))
        {
            words.push_back(token); // Store each word in the `words` vector
            count++;
        }

        int n = pattern.size();
        // If the number of words does not match the pattern length, return false
        if (count != n)
            return false;

        unordered_map<string, char> mp; // Maps each word to a pattern character
        set<char> used;                 // Set to keep track of characters already mapped to a word

        // Iterate over each character in the pattern and the corresponding word
        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            char ch = pattern[i];

            // If the word has not been mapped and the character is not yet used
            if (mp.find(word) == mp.end() && used.find(ch) == used.end())
            {
                used.insert(ch); // Mark the character as used
                mp[word] = ch;   // Create a mapping from the word to the pattern character
            }
            // If the word is already mapped but not to the current pattern character
            else if (mp[word] != ch)
            {
                return false; // Return false since the pattern doesn't match
            }
        }

        return true; // If all words match the pattern, return true
    }
};
