#include <bits/stdc++.h>
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int count = 0;
    void pathSumFromNode(TreeNode *root, long long targetSum)
    {
        if (!root)
            return;

        if (root->val == targetSum)
        {
            count++;
        }

        pathSumFromNode(root->left, targetSum - root->val);
        pathSumFromNode(root->right, targetSum - root->val);
    }
    int pathSum(TreeNode *root, long long targetSum)
    {
        if (root)
        {
            pathSumFromNode(root, targetSum);
            // for every node
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return count;
    }
};