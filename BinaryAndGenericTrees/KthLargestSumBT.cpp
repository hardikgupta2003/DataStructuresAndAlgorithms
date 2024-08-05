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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};

class Solution
{
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        queue<TreeNode *> q;
        priority_queue<long long> pq;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            long long sum = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();
                q.pop();
                sum += front->val;
                if (front->left)
                {
                    q.push(front->left);
                }
                if (front->right)
                {
                    q.push(front->right);
                }
            }
            pq.push(sum);
        }
        if (pq.size() < k)
            return -1;
        while (--k > 0)
            pq.pop();
        return pq.top();
    }
};