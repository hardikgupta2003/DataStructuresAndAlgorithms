#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordSearch(vector<vector<char>> &board, string &word, int rIndex, int cIndex, int wordIndex)
    {
        if (wordIndex == word.size())
        {
            return true;
        }
        if (rIndex < 0 || rIndex >= board.size() || cIndex < 0 ||
            cIndex >= board[0].size() || board[rIndex][cIndex] != word[wordIndex])
        {
            return false;
        }

        // do something
        char temp = board[rIndex][cIndex];
        board[rIndex][cIndex] = '#';

        // explore
        bool found = wordSearch(board, word, rIndex + 1, cIndex, wordIndex + 1) ||
                     wordSearch(board, word, rIndex, cIndex + 1, wordIndex + 1) ||
                     wordSearch(board, word, rIndex, cIndex - 1, wordIndex + 1) ||
                     wordSearch(board, word, rIndex - 1, cIndex, wordIndex + 1);

        // undo that thing
        board[rIndex][cIndex] = temp;

        return found;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int rIndex = 0; rIndex < board.size(); rIndex++)
        {
            for (int cIndex = 0; cIndex < board[0].size(); cIndex++)
            {
                if (wordSearch(board, word, rIndex, cIndex, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};