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
        if (root == NULL)
            return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
    {
        vector<int> in;
        inorder(root, in);
        vector<vector<int>> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            int q = queries[i];
            int index = lower_bound(in.begin(), in.end(), q) - in.begin();

            if (index == in.size())
            {
                ans.push_back({{in.back(), -1}});
            }
            else if (q == in[index])
            {
                ans.push_back({{q, q}});
            }
            else
            {
                if (index == 0)
                {
                    ans.push_back({{-1, in[0]}});
                }
                else
                {
                    ans.push_back({{in[index - 1], in[index]}});
                }
            }
        }
        return ans;
    }
};