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
    int solve(TreeNode *root, int val, int &parent, int height)
    {
        if (root == NULL)
            return 0;
        if (root->val == val)
        {
            return height;
        }
        parent = root->val;
        int left = solve(root->left, val, parent, height + 1);
        if (left)
        {
            return left;
        }
        parent = root->val;
        int right = solve(root->right, val, parent, height + 1);
        return right;
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (root->val == x || root->val == y)
            return false;

        int Xparent = -1;
        int Xdepth = solve(root, x, Xparent, 0);
        int Yparent = -1;
        int Ydepth = solve(root, y, Yparent, 0);

        if ((Xparent != Yparent) && (Xdepth == Ydepth))
        {
            return true;
        }
        return false;
    }
};