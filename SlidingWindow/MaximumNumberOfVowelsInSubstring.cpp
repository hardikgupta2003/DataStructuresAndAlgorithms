#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkVowel(char ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k)
    {
        int maxVowel = 0;
        int count = 0;
        // processs first k window
        for (int i = 0; i < k; i++)
        {
            int ch = s[i];
            if (checkVowel(ch))
            {
                count++;
            }
        }
        maxVowel = count;
        // process remaining window
        for (int i = k; i < s.size(); i++)
        {
            char ch = s[i];
            if (checkVowel(s[i - k]))
            {
                count--;
            }
            if (checkVowel(ch))
            {
                count++;
            }
            maxVowel = max(maxVowel, count);
        }
        return maxVowel;
    }
};

class Solution
{
public:
    // Function to check if a character is a vowel (a, e, i, o, u)
    bool checkVowel(char ch)
    {
        // If the character is any of these vowels, return true
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true;
        }
        // Otherwise, return false
        return false;
    }

    // Function to find the maximum number of vowels in any substring of length k
    int maxVowels(string s, int k)
    {
        int i = 0, j = 0; // i is the start of the window, j is the end
        int maxVowel = 0; // Keeps track of the maximum number of vowels found
        int count = 0;    // Counts the number of vowels in the current window
        int n = s.size(); // Length of the string

        // Use a sliding window approach to iterate through the string
        while (j < n)
        {
            // If the character at index j is a vowel, increase the count
            if (checkVowel(s[j]))
            {
                count++;
            }

            // If the window size reaches k (i.e., j - i + 1 == k)
            if (j - i + 1 == k)
            {
                // Update the maximum number of vowels found so far
                maxVowel = max(count, maxVowel);

                // Before moving the window forward, check if the character
                // at index i is a vowel and reduce the count accordingly
                if (checkVowel(s[i]))
                {
                    count--;
                }

                // Move the start of the window forward
                i++;
            }

            // Move the end of the window forward
            j++;
        }

        // Return the maximum number of vowels found in any window of size k
        return maxVowel;
    }
};
