// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

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
    long long result = INT_MIN;
    long long treeTotalSum = 0;
    const int MOD = 1e9 + 7;
    unordered_map<TreeNode *, long long> subtreeSum;

public:
    int maxProduct(TreeNode *root)
    {
        countSubtreesSum(root);

        dfs(root);

        return result % MOD;
    }

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;

        if (root->left)
        {
            long long first = treeTotalSum - subtreeSum[root->left];
            long long second = subtreeSum[root->left];
            result = max(result, first * second);
        }

        if (root->right)
        {
            long long first = treeTotalSum - subtreeSum[root->right];
            long long second = subtreeSum[root->right];
            result = max(result, first * second);
        }

        dfs(root->left);
        dfs(root->right);
    }

    int countSubtreesSum(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        treeTotalSum += root->val;

        subtreeSum[root] = root->val + countSubtreesSum(root->left) + countSubtreesSum(root->right);
        return subtreeSum[root];
    }
};