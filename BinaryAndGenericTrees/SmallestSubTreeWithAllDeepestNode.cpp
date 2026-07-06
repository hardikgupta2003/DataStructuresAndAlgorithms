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
    void findDepth(TreeNode *root, int &maxDepth, int depth)
    {
        if (root == NULL)
            return;
        findDepth(root->left, maxDepth, depth + 1);
        findDepth(root->right, maxDepth, depth + 1);

        if (depth > maxDepth)
        {
            maxDepth = depth;
        }
    }

    TreeNode *solve(TreeNode *root, int maxDepth)
    {
        if (root == NULL)
            return NULL;

        if (maxDepth == 1 && (!root->left && !root->right))
        {
            return root;
        }

        if (maxDepth == 1 && (root->left && !root->right))
        {
            return root->left;
        }

        if (maxDepth == 1 && (!root->left && root->right))
        {
            return root->right;
        }

        TreeNode *left = solve(root->left, maxDepth - 1);
        TreeNode *right = solve(root->right, maxDepth - 1);

        if (left && right)
            return root;
        return left ? left : right;
    }
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        int maxDepth = 0;
        findDepth(root, maxDepth, 1);

        return solve(root, maxDepth);
    }
};