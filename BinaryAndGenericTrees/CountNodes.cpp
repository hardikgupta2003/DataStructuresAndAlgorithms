#include "bits/stdc++.h"
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
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
    int solve(TreeNode *root, int &count)
    {
        if (root == NULL)
            return 0;

        int left = solve(root->left, count);
        int right = solve(root->right, count);

        return left + right + 1;
    }
    int countNodes(TreeNode *root)
    {
        int count = 0;
        return solve(root, count);
    }
};