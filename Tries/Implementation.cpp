// leetcode medium
// Implement Trie (Prefix Tree)

// https://leetcode.com/problems/implement-trie-prefix-tree/description/
// C++ code
#include <bits/stdc++.h>
using namespace std;

// // iterative loop
// class TrieNode
// {
// public:
//     TrieNode *children[26];
//     bool isEndOfWord;
//     TrieNode()
//     {
//         isEndOfWord = false;
//         for (int i = 0; i < 26; i++)
//             children[i] = NULL;
//     }
// };
// class Trie
// {
//     TrieNode *root;

// public:
//     Trie()
//     {
//         root = new TrieNode();
//     }

//     void insert(string word)
//     {
//         TrieNode *node = root;
//         for (int i = 0; i < word.length(); i++)
//         {
//             int index = word[i] - 'a';
//             if (node->children[index] == NULL)
//                 node->children[index] = new TrieNode();
//             node = node->children[index];
//         }
//         node->isEndOfWord = true;
//     }

//     bool search(string word)
//     {
//         TrieNode *node = root;
//         for (int i = 0; i < word.length(); i++)
//         {
//             int index = word[i] - 'a';
//             if (node->children[index] == NULL)
//                 return false;
//             node = node->children[index];
//         }
//         return node->isEndOfWord;
//     }

//     bool startsWith(string prefix)
//     {
//         TrieNode *node = root;
//         for (int i = 0; i < prefix.length(); i++)
//         {
//             int index = prefix[i] - 'a';
//             if (node->children[index] == NULL)
//                 return false;
//             node = node->children[index];
//         }
//         return true;
//     }
// };
// recursive way

class TrieNode
{
public:
    char value;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char val)
    {
        this->value = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};
class Trie
{
    TrieNode *root;
    void insertUtil(TrieNode *root, string &words, int i)
    {
        if (i >= words.size())
        {
            root->isTerminal = true;
            return;
        }

        int index = words[i] - 'a';
        TrieNode *children;
        if (!root->children[index])
        {
            root->children[index] = new TrieNode(words[i]);
        }
        insertUtil(root->children[index], words, i + 1);
    }

    bool searchUtil(TrieNode *root, string &words, int i)
    {
        if (i >= words.size())
        {
            return root->isTerminal;
        }

        int index = words[i] - 'a';
        if (!root->children[index])
        {
            return false;
        }
        return searchUtil(root->children[index], words, i + 1);
    }
    bool startsUtil(TrieNode *root, string &words, int i)
    {
        if (i >= words.size())
        {
            return true;
        }

        int index = words[i] - 'a';
        if (!root->children[index])
        {
            return false;
        }
        return startsUtil(root->children[index], words, i + 1);
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string word)
    {
        insertUtil(root, word, 0);
    }

    bool search(string word)
    {
        return searchUtil(root, word, 0);
    }

    bool startsWith(string prefix)
    {
        return startsUtil(root, prefix, 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */