#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
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
    bool isCompleteTree(TreeNode *root)
    {
        if (!root)
            return true;

        queue<TreeNode *> q;
        q.push(root);
        bool foundNull = false;

        while (!q.empty())
        {
            TreeNode *currentNode = q.front();
            q.pop();

            if (currentNode == NULL)
            {
                foundNull = true;
            }
            else
            {
                if (foundNull)
                    return false;
                q.push(currentNode->left);
                q.push(currentNode->right);
            }
        }
        return true;
    }
};