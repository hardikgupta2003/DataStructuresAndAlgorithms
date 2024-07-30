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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;

        if (root->val == key)
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            if (root->left != NULL && root->right == NULL)
            {
                TreeNode *child = root->left;
                delete root;
                return child;
            }
            if (root->right != NULL && root->left == NULL)
            {
                TreeNode *child = root->right;
                delete root;
                return child;
            }
            else
            {   // left and right both are not NULL
                // mini of right Subtree
                TreeNode *mini = root->right;
                while (mini->left != NULL)
                {
                    mini = mini->left;
                }
                root->val = mini->val;
                root->right = deleteNode(root->right, mini->val);
                return root;
            }
        }
        else
        {
            if (root->val > key)
            {
                root->left = deleteNode(root->left, key);
            }
            else
            {
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};