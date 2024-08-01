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
    unordered_map<int, vector<TreeNode *>> dp;

public:
    vector<TreeNode *> generateTrees(int start, int end)
    {
        int key = start * 100 + end; // Create a unique key for the pair (start, end)
        if (dp.find(key) != dp.end())
        {
            return dp[key];
        }
        vector<TreeNode *> ans;

        // Base case: if start > end, there should be an empty tree
        if (start > end)
        {
            ans.push_back(nullptr);
            return ans;
        }

        // Generate all trees with each number i as the root
        for (int i = start; i <= end; i++)
        {
            // Generate all possible left and right subtrees
            vector<TreeNode *> leftTrees = generateTrees(start, i - 1);
            vector<TreeNode *> rightTrees = generateTrees(i + 1, end);

            // Combine each left and right subtree with the root i
            for (auto left : leftTrees)
            {
                for (auto right : rightTrees)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        dp[key] = ans;
        return ans;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return generateTrees(1, n);
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
    vector<TreeNode *> generateTrees(int start, int end)
    {
        vector<TreeNode *> ans;

        // Base case: if start > end, there should be an empty tree
        if (start > end)
        {
            ans.push_back(nullptr);
            return ans;
        }

        // Generate all trees with each number i as the root
        for (int i = start; i <= end; i++)
        {
            // Generate all possible left and right subtrees
            vector<TreeNode *> leftTrees = generateTrees(start, i - 1);
            vector<TreeNode *> rightTrees = generateTrees(i + 1, end);

            // Combine each left and right subtree with the root i
            for (auto left : leftTrees)
            {
                for (auto right : rightTrees)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return generateTrees(1, n);
    }
};