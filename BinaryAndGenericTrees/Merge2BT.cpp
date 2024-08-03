#include "bits/stdc++.h"
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return NULL;

        // Jo Bhi NOT NULL ho usko return krdo
        if (!root2)
            return root1;

        if (!root1)
            return root2;

        // both are not NULL means that they are Overlapping each other
        TreeNode *mergedNode = new TreeNode(root1->val + root2->val);
        mergedNode->left = mergeTrees(root1->left, root2->left);
        mergedNode->right = mergeTrees(root1->right, root2->right);

        return mergedNode;
    }
};