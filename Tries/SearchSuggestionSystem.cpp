// leetcode medium
//  search suggestion system
//  https://leetcode.com/problems/search-suggestion-system/description/
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26]; // Pointers to children nodes
    bool isTerminal;        // Indicates if this node represents the end of a word

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

// Function to insert a word into the Trie
void insertWord(TrieNode *root, const string &word)
{
    TrieNode *node = root;
    for (char ch : word)
    {
        int index = ch - 'a';
        if (node->children[index] == nullptr)
        {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isTerminal = true;
}

// Function to find words in the Trie with the given prefix
void findWords(TrieNode *node, string &prefix, vector<string> &result)
{
    if (result.size() == 3)
        return; // Limit to 3 suggestions
    if (node->isTerminal)
    {
        result.push_back(prefix);
    }
    for (int i = 0; i < 26; i++)
    {
        if (node->children[i])
        {
            prefix.push_back('a' + i);
            findWords(node->children[i], prefix, result);
            prefix.pop_back(); // Backtrack
        }
    }
}

// Function to get suggestions based on the search word
vector<vector<string>> getSuggestions(TrieNode *root, const string &searchWord)
{
    vector<vector<string>> suggestions;
    TrieNode *node = root;
    string prefix;

    for (char ch : searchWord)
    {
        int index = ch - 'a';
        if (node->children[index] == nullptr)
        {
            break;
        }
        node = node->children[index];
        prefix.push_back(ch);

        vector<string> words;
        findWords(node, prefix, words);
        suggestions.push_back(words);
    }

    // If fewer suggestions than searchWord length, pad with empty lists
    while (suggestions.size() < searchWord.size())
    {
        suggestions.push_back({});
    }

    return suggestions;
}
class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        TrieNode *root = new TrieNode();

        for (auto &str : products)
        {
            insertWord(root, str);
        }
        vector<vector<string>> ans = getSuggestions(root, searchWord);
        return ans;
    }
};


