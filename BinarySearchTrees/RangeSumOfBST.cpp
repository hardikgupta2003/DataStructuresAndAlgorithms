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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (root == NULL)
            return 0;

        if (low <= root->val && root->val <= high)
        {
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }

        if (root->val < low)
            return rangeSumBST(root->right, low, high);

        return rangeSumBST(root->left, low, high);
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
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        vector<int> v;
        inorder(root, v);
        int lowIndex = lower_bound(v.begin(), v.end(), low) - v.begin();
        int highIndex = lower_bound(v.begin(), v.end(), high) - v.begin();
        int ans = 0;
        while (lowIndex <= highIndex)
        {
            ans += v[lowIndex];
            lowIndex++;
        }
        return ans;
    }
};