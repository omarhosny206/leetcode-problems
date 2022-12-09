// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    int result = INT_MIN;

public:
    int maxAncestorDiff(TreeNode *root)
    {
        dfs(root, root->val, root->val);
        return result;
    }

    void dfs(TreeNode *root, int subtreeMaxValue, int subtreeMinValue)
    {
        if (root == nullptr)
            return;

        subtreeMinValue = min(subtreeMinValue, root->val);
        subtreeMaxValue = max(subtreeMaxValue, root->val);

        result = max(result, abs(subtreeMaxValue - subtreeMinValue));

        dfs(root->left, subtreeMaxValue, subtreeMinValue);
        dfs(root->right, subtreeMaxValue, subtreeMinValue);
    }
};