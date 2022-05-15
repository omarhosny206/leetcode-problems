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
public:
    int deepestLeavesSum(TreeNode *root)
    {
        int maxDepth = getDepth(root);
        return dfs(root, 1, maxDepth);
    }

    int dfs(TreeNode *root, int currentDepth, int maxDepth)
    {
        if (root == nullptr)
            return 0;

        if (currentDepth == maxDepth)
            return root->val;

        return dfs(root->left, currentDepth + 1, maxDepth) + dfs(root->right, currentDepth + 1, maxDepth);
    }

    int getDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int left = getDepth(root->left);
        int right = getDepth(root->right);

        return 1 + max(left, right);
    }
};