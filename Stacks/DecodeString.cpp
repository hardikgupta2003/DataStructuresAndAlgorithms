#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to decode the given encoded string
    string decodeString(string s)
    {
        stack<char> st;  // Stack to keep track of characters and numbers
        string ans = ""; // To store the final decoded string

        // Loop through each character in the string
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];   // Current character
            string temp = ""; // Temporary string to store characters within brackets

            // If the current character is not a closing bracket, push it onto the stack
            if (ch != ']')
            {
                st.push(ch);
            }
            else
            { // If the current character is a closing bracket
                // Pop characters from the stack until an opening bracket is found
                while (!st.empty() && st.top() != '[')
                {
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop(); // Remove the opening bracket '[' from the stack

                string numCh = ""; // To store the number (which tells how many times to repeat the string)
                // Pop digits from the stack to form the number
                while (!st.empty() && isdigit(st.top()))
                {
                    numCh.push_back(st.top());
                    st.pop();
                }
                // Reverse the string to get the correct number
                reverse(numCh.begin(), numCh.end());
                int num = stoi(numCh); // Convert the string to an integer

                string encodedString = ""; // To store the repeated string
                // Repeat the temp string 'num' times
                while (num--)
                {
                    encodedString += temp;
                }

                // Reverse the encoded string to maintain the correct order
                reverse(encodedString.begin(), encodedString.end());

                // Push the characters of the encoded string back onto the stack
                for (int i = 0; i < encodedString.size(); i++)
                {
                    st.push(encodedString[i]);
                }
            }
        }

        // Pop all characters from the stack to form the final decoded string
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        // Reverse the final string to get the correct order
        reverse(ans.begin(), ans.end());
        return ans; // Return the decoded string
    }
};
