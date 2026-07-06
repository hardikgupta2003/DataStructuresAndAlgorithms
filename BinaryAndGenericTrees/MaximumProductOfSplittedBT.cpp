class Solution
{
public:
    long long totalSum = 0;
    long long maxProductAns = 0;

    // Step 1: Calculate total sum of tree
    void getTotalSum(TreeNode *root)
    {
        if (!root)
            return;
        totalSum += root->val;
        getTotalSum(root->left);
        getTotalSum(root->right);
    }

    // Step 2: Calculate subtree sums and product
    long long dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long subTreeSum = leftSum + rightSum + root->val;

        long long product = subTreeSum * (totalSum - subTreeSum);
        maxProductAns = max(maxProductAns, product);

        return subTreeSum;
    }

    int maxProduct(TreeNode *root)
    {
        getTotalSum(root);
        dfs(root);

        return maxProductAns % 1000000007;
    }
};
