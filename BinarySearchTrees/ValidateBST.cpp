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
    bool solve(TreeNode *root, long long lb, long long ub)
    {
        if (root == NULL)
        {
            return true;
        }

        bool cond1 = (root->val > lb);
        bool cond2 = (root->val < ub);
        bool leftAns = solve(root->left, lb, root->val);
        bool rightAns = solve(root->right, root->val, ub);

        if (cond1 && cond2 && leftAns && rightAns)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isValidBST(TreeNode *root)
    {
        long long lb = LONG_MIN;
        long long ub = LONG_MAX;

        bool ans = solve(root, lb, ub);
        return ans;
    }
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
    bool solve(TreeNode *root, long lb, long ub)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (root->val <= lb || root->val >= ub)
        {
            return false;
        }

        return solve(root->left, lb, root->val) && solve(root->right, root->val, ub);
    }

    bool isValidBST(TreeNode *root)
    {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};