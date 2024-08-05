#include <bits/stdc++.h>
using namespace std;



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution
{
public:
    void solve(TreeNode *root, int maxVal, int &count)
    {
        if (root == NULL)
            return;

        if (root->val >= maxVal)
        {
            count++;
            maxVal = root->val;
        }

        // cout<<root->val<<endl;
        solve(root->left, maxVal, count);
        solve(root->right, maxVal, count);
    }
    int goodNodes(TreeNode *root)
    {
        int count = 0;
        solve(root, root->val, count);
        return count;
    }
};