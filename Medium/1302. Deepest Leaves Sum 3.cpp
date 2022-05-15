// https://leetcode.com/problems/deepest-leaves-sum/

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
    int result = 0;
    int maxDepth = 0;

public:
    int deepestLeavesSum(TreeNode *root)
    {
        dfs(root, 0);
        return result;
    }

    void dfs(TreeNode *root, int currentDepth)
    {
        if (root == nullptr)
            return;

        if (maxDepth < currentDepth)
            result = 0;

        if (root->left == nullptr && root->right == nullptr && currentDepth >= maxDepth)
            result += root->val;

        maxDepth = max(maxDepth, currentDepth);

        dfs(root->left, currentDepth + 1);
        dfs(root->right, currentDepth + 1);
    }
};