// leetcode medium
// vertical order of the binary tree
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        map<int, map<int, multiset<int>>> mp;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            TreeNode *Node = front.first;
            auto coordinates = front.second;
            int row = coordinates.first;
            int col = coordinates.second;

            mp[col][row].insert(Node->val);
            if (Node->left)
            {
                q.push({Node->left, {row + 1, col - 1}});
            }
            if (Node->right)
            {
                q.push({Node->right, {row + 1, col + 1}});
            }
        }
        // now store the output in the ans vector
        for (auto it : mp)
        {
            auto &colMap = it.second;
            vector<int> vLine;
            for (auto colMapIt : colMap)
            {
                auto &mset = colMapIt.second;
                vLine.insert(vLine.end(), mset.begin(), mset.end());
            }
            ans.push_back(vLine);
        }
        return ans;
    }
};