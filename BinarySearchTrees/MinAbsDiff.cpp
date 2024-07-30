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
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    int getMinimumDifference(TreeNode *root)
    {
        if (!root)
            return 0;
        vector<int> ans;
        inorder(root, ans);
        int res = abs(ans[0] - ans[1]);
        for (int i = 2; i < ans.size(); i++)
        {
            res = min(res, abs(ans[i] - ans[i - 1]));
        }
        return res;
    }
};