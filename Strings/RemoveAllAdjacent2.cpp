// Medium LeetCode: Remove All Adjacent Duplicates in String II
// Problem Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Removes all adjacent duplicates in a string where k consecutive identical characters are found.
 * 
 * Approach:
 * - We use a stack to keep track of characters and their consecutive frequencies (counts).
 * - For each character in the string:
 *   1. If the stack is not empty and the top character matches the current character,
 *      we increment the frequency count of the top element.
 *   2. If the frequency count reaches `k`, we pop the element from the stack.
 *   3. If the top character doesn't match or the stack is empty, we push the character with a count of 1.
 * - After processing the entire string, we rebuild the result string from the stack.
 * - Since the stack pops in reverse order, we reverse the reconstructed string at the end.
 * 
 * Time Complexity: O(N) where N is the length of the string, since we process each character at most twice.
 * Space Complexity: O(N) to store the characters and their counts in the stack.
 */
string removeDuplicates(string s, int k)
{
    // Stack of pairs: {character, consecutive count}
    stack<pair<char, int>> st;
    
    for (char c : s)
    {
        // If the stack is not empty and the current character matches the stack's top character
        if (!st.empty() && st.top().first == c)
        {
            st.top().second++; // Increment the consecutive count
            
            // If the count reaches k, remove these duplicate characters
            if (st.top().second == k)
            {
                st.pop();
            }
        }
        else
        {
            // Otherwise, push the new character with an initial count of 1
            st.push({c, 1});
        }
    }
    
    // Reconstruct the remaining characters from the stack
    string res = "";
    while (!st.empty())
    {
        // Add the character repeated by its consecutive count times
        res += string(st.top().second, st.top().first);
        st.pop();
    }
    
    // Since we popped from a stack, the characters are in reverse order
    reverse(res.begin(), res.end());
    
    return res;
}

// Driver code to test the implementation
int main()
{
    // Test Case 1: Simple case with no adjacent duplicates of length k
    string s1 = "abcd";
    int k1 = 2;
    cout << "Test Case 1:" << endl;
    cout << "Input string: \"" << s1 << "\", k = " << k1 << endl;
    cout << "Output:       \"" << removeDuplicates(s1, k1) << "\"" << endl;
    cout << "Expected:     \"abcd\"" << endl << endl;

    // Test Case 2: Consecutive duplicates that trigger cascade removal
    string s2 = "deeedbbcccbdaa";
    int k2 = 3;
    cout << "Test Case 2:" << endl;
    cout << "Input string: \"" << s2 << "\", k = " << k2 << endl;
    cout << "Output:       \"" << removeDuplicates(s2, k2) << "\"" << endl;
    cout << "Expected:     \"aa\"" << endl << endl;

    // Test Case 3: Multiple different duplicates to be removed
    string s3 = "pbbcggttciiippooaais";
    int k3 = 2;
    cout << "Test Case 3:" << endl;
    cout << "Input string: \"" << s3 << "\", k = " << k3 << endl;
    cout << "Output:       \"" << removeDuplicates(s3, k3) << "\"" << endl;
    cout << "Expected:     \"ps\"" << endl << endl;

    return 0;
}
