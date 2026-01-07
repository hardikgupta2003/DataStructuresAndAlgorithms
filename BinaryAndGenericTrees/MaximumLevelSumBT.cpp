/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int level = 1;
        int maxlevel = 1;

        queue<TreeNode *> q;
        int sum = 0;
        int maxi = INT_MIN;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front != NULL)
            {
                sum += front->val;
                if (front->left != NULL)
                {
                    q.push(front->left);
                }
                if (front->right != NULL)
                {
                    q.push(front->right);
                }
            }
            else
            {
                if (sum > maxi)
                {
                    maxi = sum;
                    maxlevel = level;
                }
                level++;

                if (!q.empty())
                {
                    q.push(NULL);
                    sum = 0;
                }
            }
        }

        return maxlevel;
    }
};